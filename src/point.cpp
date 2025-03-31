#include "point.h"


_DRAWING_BEGIN


Point::Point(std::size_t x, std::size_t y)
    : _x(x), _y(y)
{    }

std::size_t
Point::x() const noexcept
{ return _x; }

std::size_t
Point::y() const noexcept
{ return _y; }

_DRAWING_END

