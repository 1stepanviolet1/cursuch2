#pragma once


#ifndef _FIGURE_H
#define _FIGURE_H

#include "image.h"

_DRAWING_BEGIN

class Figure
{
public:
    virtual void draw(png::Image &_image) const = 0;
    virtual ~Figure() = 0;

};

enum figure_type
{
    line = 'L',
    mirror = 'M',
    pentagram = 'P',
    null = 0
};

_DRAWING_END


#endif // _FIGURE_H

