#pragma once


#ifndef _POINT_H
#define _POINT_H

#include "options.h"

_DRAWING_BEGIN

class Point
{
public:
    constexpr Point(std::int64_t x, std::int64_t y)
        : _x(x), _y(y)
    {    }

    constexpr Point() : Point(0, 0) 
    {    }

    constexpr std::int64_t x() const noexcept
    { return this->_x; }
    constexpr std::int64_t y() const noexcept
    { return this->_y; }

protected:
    std::int64_t _x;
    std::int64_t _y;

};

_DRAWING_END


#endif // _POINT_H

