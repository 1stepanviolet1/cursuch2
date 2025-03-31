#pragma once


#ifndef _CIRCLE_H
#define _CIRCLE_H

#include <cmath>

#include "figure.h"
#include "builder.h"

_DRAWING_BEGIN

class Circle : public Figure
{
    friend class BUILDER(Circle);

public:
    Circle();

    void draw(png::Image &_image) const override;

    ~Circle() override = default;

private:
    Point _center;
    std::size_t _radius;
    png::Color _color;

};

_DRAWING_END


#endif // _CIRCLE_H

