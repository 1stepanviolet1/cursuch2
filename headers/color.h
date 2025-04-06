#pragma once


#ifndef _COLOR_H
#define _COLOR_H

#include <png.h>
#include <iostream>

#include "options.h"

#define REG_GETTER_COLOR_CHANNEL(_C) \
    png_byte _C() const noexcept;

#define REG_SETTER_COLOR_CHANNEL(_C) \
    png_byte _C(std::size_t _v);

#define REALIZE_GETTER_COLOR_CHANNEL(_C)    \
    png_byte                                \
    Color::_C() const noexcept              \
    { return this->_##_C; }

#define REALIZE_SETTER_COLOR_CHANNEL(_C)                            \
    png_byte                                                        \
    Color::_C(std::size_t _v)                                       \
    {                                                               \
        if (_v > 256)                                               \
            throw std::invalid_argument("Invalid RGB color value"); \
                                                                    \
        return this->_##_C = static_cast<png_byte>(_v);             \
    }

_PNG_BEGIN

class Color
{
public:
    explicit Color(std::size_t _r, std::size_t _g, std::size_t _b, std::size_t _a);
    explicit Color(std::size_t _r, std::size_t _g, std::size_t _b);
    explicit Color();

    REG_GETTER_COLOR_CHANNEL(r)
    REG_GETTER_COLOR_CHANNEL(g)
    REG_GETTER_COLOR_CHANNEL(b)
    REG_GETTER_COLOR_CHANNEL(a)

    REG_SETTER_COLOR_CHANNEL(r)
    REG_SETTER_COLOR_CHANNEL(g)
    REG_SETTER_COLOR_CHANNEL(b)
    REG_SETTER_COLOR_CHANNEL(a)

    ~Color() noexcept = default;

protected:
    png_byte _r;
    png_byte _g;
    png_byte _b;
    png_byte _a;
    
};

_PNG_END


#endif // _COLOR_H

