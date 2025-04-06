#include "mirror_builder.h"


_DRAWING_BEGIN

REALIZE_BUILDER_DEFAULT_METHODS(Mirror)

BUILDER(Mirror)&
BUILDER(Mirror)::setup_axis(Axis _a)
{
    this->REF(Mirror)->_axis = _a; 
    return *this; 
}

BUILDER(Mirror)&
BUILDER(Mirror)::setup_axis(const char _a)
{
    this->setup_axis(make_axis(_a)); 
    return *this; 
}

BUILDER(Mirror)&
BUILDER(Mirror)::setup_left_up(const Point &_l_u)
{
    this->REF(Mirror)->_left_up = _l_u; 
    return *this; 
}

BUILDER(Mirror)&
BUILDER(Mirror)::setup_right_down(const Point &_r_d)
{
    this->REF(Mirror)->_right_down = _r_d; 
    return *this; 
}

_DRAWING_END

