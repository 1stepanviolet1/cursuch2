#include "objects.hpp"


namespace obj
{

void
PNG::_png_constructor()
{
    this->_fp = this->_open_file(this->_ifilename, "rb");

    this->_check_png_sig(this->_fp);

    this->_png_rptr = this->_create_read_struct();
    
    this->_info_ptr = this->_create_info_struct();

    if (setjmp(png_jmpbuf(this->_png_rptr)))
    {
        this->~PNG();
        std::exit(FAILURE_CODE);
    }

    png_init_io(this->_png_rptr, this->_fp);
    png_set_sig_bytes(this->_png_rptr, 8);

    png_read_png(this->_png_rptr, this->_info_ptr, PNG_TRANSFORM_IDENTITY, nullptr);

}

FILE * 
PNG::_open_file(std::string filename, std::string mode)
{
    FILE *_fp = fopen(filename.data(), mode.data());

    if (!_fp) 
    {
        this->~PNG();
        std::cout << "Ошибка открытия файла \"" << filename << '\"' << std::endl;
        std::exit(FAILURE_CODE);

    }

    return _fp;

}

void 
PNG::_check_png_sig(FILE *_fp)
{
    png_byte sig[8];
    fread(sig, 1, 8, _fp);
    if (!png_check_sig(sig, 8))
    {
        this->~PNG();
        std::cout << "Файл " << this->_ifilename << " не является допустимым PNG-файлом" << std::endl;
        std::exit(FAILURE_CODE);
    }

}

png_structp 
PNG::_create_read_struct()
{
    png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
    if (!png_ptr) 
    {
        this->~PNG();
        std::cout << "Ошибка при создании png_struct" << std::endl;
        std::exit(FAILURE_CODE);
    }

    return png_ptr;

}

png_infop 
PNG::_create_info_struct()
{
    png_infop info_ptr = png_create_info_struct(this->_png_rptr);
    if (!info_ptr) 
    {
        this->~PNG();
        std::cout << "Ошибка при создании png_info" << std::endl;
        std::exit(FAILURE_CODE);
    }

    return info_ptr;

}

void 
PNG::_write(std::string output_file)
{
    FILE *_out_fp = this->_open_file(output_file, "wb");

    png_structp _png_wptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);

    if (!_png_wptr)
    {
        std::cout << "Ошибка при создании png_struct" << std::endl;
        fclose(_out_fp);
        std::exit(FAILURE_CODE);
    }

    if (setjmp(png_jmpbuf(_png_wptr)))
    {
        this->~PNG();
        fclose(_out_fp);
        png_destroy_write_struct(&_png_wptr, nullptr);
        std::exit(FAILURE_CODE);
    }

    png_init_io(_png_wptr, _out_fp);

    png_write_png(_png_wptr, this->_info_ptr, PNG_TRANSFORM_IDENTITY, nullptr);

    fclose(_out_fp);
    png_destroy_write_struct(&_png_wptr, nullptr);

}

PNG::~PNG()
{
    if (this->_fp)
        fclose(this->_fp);

    if (this->_png_rptr)
        png_destroy_read_struct(&(this->_png_rptr), nullptr, nullptr);

    if (this->_info_ptr)
        png_destroy_info_struct(nullptr, &(this->_info_ptr));

}

};
