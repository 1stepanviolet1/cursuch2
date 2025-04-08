#include "image.h"


_PNG_BEGIN

Image::Image(const std::string &filename)
{
    if (!filename.empty())
        this->load(filename);

}

void 
Image::load(const std::string &filename) 
{
    this->_clear_read_data();
    this->_check_png(filename);

    FILE *file = fopen(filename.c_str(), "rb");
    if (!file)
        throw std::invalid_argument("Error: Cannot open file");

    png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
    if (!png)
    {
        fclose(file);
        throw std::invalid_argument("Error: Cannot create png_struct");
    }

    png_infop info = png_create_info_struct(png);
    if (!info)
    {
        png_destroy_read_struct(&png, nullptr, nullptr);
        fclose(file);
        throw std::invalid_argument("Error: Cannot create info_struct");
    }

    if (setjmp(png_jmpbuf(png)))
    {
        png_destroy_read_struct(&png, &info, nullptr);
        fclose(file);
        throw std::invalid_argument("Error: bad setjmp(png_jmpbuf(png))");
    }

    png_init_io(png, file);

    png_read_png(png, info, PNG_TRANSFORM_IDENTITY, NULL);

    this->_png_read_ptr = png;
    this->_info_read_ptr = info;

    this->_rows = png_get_rows(png, info);
    this->_channels = png_get_channels(png, info);

    this->_width = png_get_image_width(png, info);
    this->_height = png_get_image_height(png, info);

    this->_color_type = png_get_color_type(png, info);
    this->_bit_depth = png_get_bit_depth(png, info);
    this->_interlace_type = png_get_interlace_type(png, info);
    this->_compression_type = png_get_compression_type(png, info);
    this->_filter_type = png_get_filter_type(png, info);

    fclose(file);
    
}


void 
Image::save(const std::string &filename)
{
    if (this->_png_read_ptr == NULL || this->_info_read_ptr == NULL)
        throw std::invalid_argument("Error: No image data to save");

    FILE *file = fopen(filename.c_str(), "wb");
    if (!file)
        throw std::invalid_argument("Error: Cannot open file");

    png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
    if (!png)
    {
        fclose(file);
        throw std::invalid_argument("Error: Cannot create png_struct");
    }

    png_infop info = png_create_info_struct(png);
    if (!info)
    {
        png_destroy_write_struct(&png, nullptr);
        fclose(file);
        throw std::invalid_argument("Error: Cannot create info_struct");
    }

    if (setjmp(png_jmpbuf(png)))
    {
        png_destroy_write_struct(&png, &info);
        fclose(file);
        throw std::invalid_argument("Error: bad setjmp(png_jmpbuf(png))");
    }

    png_init_io(png, file);
    png_set_IHDR(png, info, 
                 this->_width, this->_height,
                 this->_bit_depth, this->_color_type, 
                 this->_interlace_type,
                 this->_compression_type,
                 this->_filter_type);
    
    png_set_rows(png, info, this->_rows);
    
    png_write_png(png, info, PNG_TRANSFORM_IDENTITY, NULL);
    
    png_destroy_write_struct(&png, &info);
    fclose(file);

}

Color 
Image::pixel(const drawing::Point &_p) const
{
    if (_p.x() >= this->_width || _p.y() >= this->_height)
        throw std::invalid_argument("Error: Invalid pixel coordinates");

    
    return Color(
        this->_rows[_p.y()][_p.x() * this->_channels], 
        this->_rows[_p.y()][_p.x() * this->_channels + 1], 
        this->_rows[_p.y()][_p.x() * this->_channels + 2],
        this->_channels > 3 
            ? this->_rows[_p.y()][_p.x() * this->_channels + 3]
            : 255
    );
}

Color 
Image::pixel(const drawing::Point &_p, const Color &color)
{
    if (_p.x() >= this->_width || _p.y() >= this->_height) 
        throw std::invalid_argument("Error: Invalid pixel coordinates");

    this->_rows[_p.y()][_p.x() * this->_channels] = color.r();
    this->_rows[_p.y()][_p.x() * this->_channels + 1] = color.g();
    this->_rows[_p.y()][_p.x() * this->_channels + 2] = color.b();
    if (this->_channels > 3)
        this->_rows[_p.y()][_p.x() * this->_channels + 3] = color.a();

    return color;

}

std::size_t 
Image::width() const noexcept
{ return this->_width; }

std::size_t
Image::height() const noexcept
{ return this->_height; }


Image::~Image()
{
    this->_clear_read_data();

}

void 
Image::_clear_read_data()
{
    if (this->_png_read_ptr == NULL && this->_info_read_ptr == NULL)
        return;
    
    png_destroy_read_struct(&this->_png_read_ptr, &this->_info_read_ptr, NULL);
    this->_png_read_ptr = NULL;
    this->_info_read_ptr = NULL;
    this->_rows = NULL;

}


void
Image::_check_png(const std::string &filename)
{
    FILE *file = fopen(filename.c_str(), "rb");
    if (!file)
        throw std::invalid_argument("Error: Cannot open file");

    png_byte signature[8];
    fread(signature, 1, 8, file);
    if (png_sig_cmp(signature, 0, 8)) 
    {
        fclose(file);
        throw std::runtime_error("Error: File is not a valid PNG (invalid signature)");
    }

    fclose(file);

}

_PNG_END

