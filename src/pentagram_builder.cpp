#include "pentagram_builder.h"


_DRAWING_BEGIN

REALIZE_BUILDER_DEFAULT_METHODS(Pentagram)

BUILDER(Pentagram)&
BUILDER(Pentagram)::setup_center(const Point &_c)
{
    this->REF(Pentagram)->_center = _c; 
    return *this; 
}

BUILDER(Pentagram)&
BUILDER(Pentagram)::setup_radius(std::uint64_t _r)
{
    if (_r < 1)
        throw std::invalid_argument("Pentagram radius must be greater than 0");

    this->REF(Pentagram)->_radius = _r; 
    return *this; 
}

BUILDER(Pentagram)&
BUILDER(Pentagram)::setup_thickness(std::size_t _t)
{
    if (_t < 1)
        throw std::invalid_argument("Pentagram thickness must be greater than 0");

    this->REF(Pentagram)->_thickness = _t; 
    return *this; 
}

BUILDER(Pentagram)&
BUILDER(Pentagram)::setup_color(const png::Color &_c)
{
    this->REF(Pentagram)->_color = _c; 
    return *this; 
}

_DRAWING_END

