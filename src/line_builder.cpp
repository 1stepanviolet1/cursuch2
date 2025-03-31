#include "line_builder.h"


_DRAWING_BEGIN

REG_BUILDER_GETTER(Line)

BUILDER(Line)&
BUILDER(Line)::setup_start(const Point &_s_p)
{
    this->REF(Line)._start_point = _s_p; 
    return *this; 
}

BUILDER(Line)&
BUILDER(Line)::setup_end(const Point &_e_p)
{
    this->REF(Line)._end_point = _e_p; 
    return *this; 
}

BUILDER(Line)&
BUILDER(Line)::setup_color(const png::Color &_c)
{
    this->REF(Line)._color = _c; 
    return *this; 
}

BUILDER(Line)&
BUILDER(Line)::setup_thickness(std::size_t _t)
{
    if (_t < 1)
        throw std::invalid_argument("Line thickness must be greater than 0");

    this->REF(Line)._thickness = _t; 
    return *this; 
}

_DRAWING_END

