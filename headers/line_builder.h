#pragma once


#ifndef _LINE_BUILDER_H
#define _LINE_BUILDER_H

#include "builder.h"
#include "line.h"

_DRAWING_BEGIN

REG_BUILDER_BEGIN(Line)

    BUILDER(Line)& setup_start(const Point &_s_p);
    BUILDER(Line)& setup_end(const Point &_e_p);
    BUILDER(Line)& setup_color(const png::Color &_c);
    BUILDER(Line)& setup_thickness(std::size_t _t);

REG_BUILDER_END(Line)

_DRAWING_END


#endif // _LINE_BUILDER_H

