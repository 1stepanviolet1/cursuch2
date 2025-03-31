#include "circle_builder.h"


_DRAWING_BEGIN

REG_BUILDER_DEFAULT_METHODS(Circle)

BUILDER(Circle)&
BUILDER(Circle)::setup_center(const Point &_c)
{
    this->REF(Circle)->_center = _c; 
    return *this; 
}

BUILDER(Circle)&
BUILDER(Circle)::setup_radius(std::size_t _r)
{
    if (_r < 1)
        throw std::invalid_argument("Circle radius must be greater than 0");

    this->REF(Circle)->_radius = _r; 
    return *this; 
}

BUILDER(Circle)&
BUILDER(Circle)::setup_color(const png::Color &_c)
{
    this->REF(Circle)->_color = _c; 
    return *this; 
}

_DRAWING_END

