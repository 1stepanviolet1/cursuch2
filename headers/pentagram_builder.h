#pragma once


#ifndef _PENTAGRAM_BUILDER_H
#define _PENTAGRAM_BUILDER_H

#include "builder.h"
#include "pentagram.h"

_DRAWING_BEGIN

REG_BUILDER_BEGIN(Pentagram)

    BUILDER(Pentagram)& setup_center(const Point &_c);
    BUILDER(Pentagram)& setup_radius(std::size_t _r);
    BUILDER(Pentagram)& setup_thickness(std::size_t _t);
    BUILDER(Pentagram)& setup_color(const png::Color &_c);

REG_BUILDER_END(Pentagram)

_DRAWING_END


#endif // _PENTAGRAM_BUILDER_H

