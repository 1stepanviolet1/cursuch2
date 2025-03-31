#pragma once


#ifndef _MIRROR_H
#define _MIRROR_H

#include "figure.h"
#include "builder.h"

_DRAWING_BEGIN

enum class Axis : char
{
    X = 'x',
    Y = 'y'
};

class Mirror : public Figure
{
    friend class BUILDER(Mirror);

public:
    Mirror();

    void draw(png::Image &_image) const override;

    ~Mirror() override = default;

private:
    Axis _axis;
    Point _left_up;
    Point _right_down;

};

_DRAWING_END


#endif // _MIRROR_H

