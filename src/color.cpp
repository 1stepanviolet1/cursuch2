#include "color.h"


_PNG_BEGIN

Color::Color(std::size_t _r, std::size_t _g, std::size_t _b)
{
    this->r(_r);
    this->g(_g);
    this->b(_b);

}

Color::Color()
{
    this->r(0);
    this->g(0);
    this->b(0);
    
}

png_byte 
Color::r() const noexcept
{ return this->_r; }

png_byte 
Color::g() const noexcept
{ return this->_g; }

png_byte 
Color::b() const noexcept
{ return this->_b; }


png_byte 
Color::r(std::size_t _v) noexcept
{
    if (_v > 256)
    {
        std::cerr << "Invalid RGB(r) color value: " << _v << std::endl;
        std::exit(exitcode::ERROR);
    }

    return this->_r = static_cast<png_byte>(_v);

}

png_byte 
Color::g(std::size_t _v) noexcept
{
    if (_v > 256)
    {
        std::cerr << "Invalid RGB(g) color value: " << _v << std::endl;
        std::exit(exitcode::ERROR);
    }

    return this->_g = static_cast<png_byte>(_v);

}

png_byte 
Color::b(std::size_t _v) noexcept
{
    if (_v > 256)
    {
        std::cerr << "Invalid RGB(b) color value: " << _v << std::endl;
        std::exit(exitcode::ERROR);
    }

    return this->_b = static_cast<png_byte>(_v);

}


_PNG_END

