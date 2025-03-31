#pragma once


#ifndef _POINT_H
#define _POINT_H

#include "options.h"

_DRAWING_BEGIN

class Point
{
public:
    Point(std::size_t x, std::size_t y);

    std::size_t x() const noexcept;
    std::size_t y() const noexcept;

protected:
    std::size_t _x;
    std::size_t _y;

};

_DRAWING_END


#endif // _POINT_H

