#pragma once


#ifndef _COLOR_H
#define _COLOR_H

#include <png.h>
#include <iostream>

#include "options.h"

_PNG_BEGIN

class Color
{
public:
    explicit Color(std::size_t _r, std::size_t _g, std::size_t _b);
    Color();

    png_byte r() const noexcept;
    png_byte g() const noexcept;
    png_byte b() const noexcept;

    png_byte r(std::size_t _v) noexcept;
    png_byte g(std::size_t _v) noexcept;
    png_byte b(std::size_t _v) noexcept;

    ~Color() noexcept = default;

protected:
    png_byte _r;
    png_byte _g;
    png_byte _b;
    
};

_PNG_END


#endif // _COLOR_H

