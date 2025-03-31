#pragma once


#ifndef _CIRCLE_BUILDER_H
#define _CIRCLE_BUILDER_H

#include "builder.h"
#include "circle.h"

_DRAWING_BEGIN

REG_BUILDER_BEGIN(Circle)

    BUILDER(Circle)& setup_center(const Point &_c);
    BUILDER(Circle)& setup_radius(std::size_t _r);
    BUILDER(Circle)& setup_color(const png::Color &_c);

REG_BUILDER_END(Circle)

_DRAWING_END


#endif // _CIRCLE_BUILDER_H

