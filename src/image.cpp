#include "image.h"


_PNG_START

Image::Image(const std::string &filename)
{
    if (!filename.empty())
        this->load(filename);

}

void 
Image::load(const std::string &filename) 
{
    this->_clear_read_data();

    FILE *file = fopen(filename.c_str(), "rb");
    if (!file) {
        std::cerr << "Error: Cannot open file " << filename << std::endl;
        std::exit(exitcode::ERROR);
    }

    this->_check_png(file);

    png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
    if (!png) {
        std::cerr << "Error: Cannot create png_struct" << std::endl;
        fclose(file);
        std::exit(exitcode::ERROR);
    }

    png_infop info = png_create_info_struct(png);
    if (!info) {
        std::cerr << "Error: Cannot create info_struct" << std::endl;
        png_destroy_read_struct(&png, nullptr, nullptr);
        fclose(file);
        std::exit(exitcode::ERROR);
    }

    if (setjmp(png_jmpbuf(png))) {
        std::cerr << "Error: bad setjmp(png_jmpbuf(png))" << std::endl;
        png_destroy_read_struct(&png, &info, nullptr);
        fclose(file);
        std::exit(exitcode::ERROR);
    }

    png_init_io(png, file);

    png_read_png(png, info, NULL, NULL);

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
    {
        std::cerr << "Error: No image data to save" << std::endl;
        std::exit(exitcode::ERROR);
    }

    FILE *file = fopen(filename.c_str(), "wb");
    if (!file) {
        std::cerr << "Error: Cannot open file " << filename << std::endl;
        std::exit(exitcode::ERROR);
    }

    png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
    if (!png) {
        std::cerr << "Error: Cannot create png_struct" << std::endl;
        fclose(file);
        std::exit(exitcode::ERROR);
    }

    png_infop info = png_create_info_struct(png);
    if (!info) {
        std::cerr << "Error: Cannot create info_struct" << std::endl;
        png_destroy_write_struct(&png, nullptr);
        fclose(file);
        std::exit(exitcode::ERROR);
    }

    if (setjmp(png_jmpbuf(png))) {
        std::cerr << "Error: bad setjmp(png_jmpbuf(png))" << std::endl;
        png_destroy_write_struct(&png, &info);
        fclose(file);
        std::exit(exitcode::ERROR);
    }

    png_init_io(png, file);
    png_set_IHDR(png, info, 
                 this->_width, this->_height,
                 this->_bit_depth, this->_color_type, 
                 this->_interlace_type,
                 this->_compression_type,
                 this->_filter_type);
    
    png_set_rows(png, info, this->_rows);
    png_write_png(png, info, NULL, NULL);
    
    png_destroy_write_struct(&png, &info);
    fclose(file);

}

Color 
Image::pixel(std::size_t x, std::size_t y) const
{
    if (x >= this->_width || y >= this->_height) {
        std::cerr << "Error: Invalid pixel coordinates" << std::endl;
        std::exit(exitcode::ERROR);
    }

    return Color(
        this->_rows[y][x * this->_channels], 
        this->_rows[y][x * this->_channels + 1], 
        this->_rows[y][x * this->_channels + 2]
    );
}

Color 
Image::pixel(std::size_t x, std::size_t y, const Color &color)
{
    if (x >= this->_width || y >= this->_height) {
        std::cerr << "Error: Invalid pixel coordinates" << std::endl;
        std::exit(exitcode::ERROR);
    }

    this->_rows[y][x * this->_channels] = color.r();
    this->_rows[y][x * this->_channels + 1] = color.g();
    this->_rows[y][x * this->_channels + 2] = color.b();
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
    
    png_destroy_read_struct(&this->_png_read_ptr, &this->_info_read_ptr, nullptr);
    this->_png_read_ptr = nullptr;
    this->_info_read_ptr = nullptr;
    this->_rows = nullptr;

}


void
Image::_check_png(FILE *file) const
{
    png_byte signature[8];
    fread(signature, 1, 8, file);
    if (!png_sig_cmp(signature, 0, 8)) {
        std::cerr << "Error: File is not a valid PNG (invalid signature)" << std::endl;
        fclose(file);
        std::exit(exitcode::ERROR);
    }

}

_PNG_END

