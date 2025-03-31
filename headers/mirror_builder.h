#pragma once


#ifndef _MIRROR_BUILDER_H
#define _MIRROR_BUILDER_H

#include "builder.h"
#include "mirror.h"

_DRAWING_BEGIN

REG_BUILDER_BEGIN(Mirror)

    BUILDER(Mirror)& setup_axis(Axis _a);
    BUILDER(Mirror)& setup_left_up(const Point &_l_u);
    BUILDER(Mirror)& setup_right_down(const Point &_r_d);

REG_BUILDER_END(Mirror)

_DRAWING_END


#endif // _MIRROR_BUILDER_H

