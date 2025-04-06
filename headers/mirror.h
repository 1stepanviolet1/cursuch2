#pragma once


#ifndef _MIRROR_H
#define _MIRROR_H

#include "figure.h"
#include "builder.h"

_DRAWING_BEGIN

enum class Axis : char
{
    X = 'x',
    Y = 'y',
    null = 0
};

constexpr Axis 
make_axis(const char _c = 0)
{
    switch (_c)
    {
    case static_cast<char>(Axis::X):
        return Axis::X;

    case static_cast<char>(Axis::Y):
        return Axis::Y;

    default:
        return Axis::null;

    }

}

class Mirror : public Figure
{
    friend class BUILDER(Mirror);

public:
    constexpr Mirror()
        : _axis(make_axis()), _left_up({0, 0}), _right_down({0, 0})
    {    }

    void draw(png::Image &_image) const override;

    ~Mirror() override = default;

private:
    Axis _axis;
    Point _left_up;
    Point _right_down;

private:
    void __draw_x_mirror(png::Image &_image) const;
    void __draw_y_mirror(png::Image &_image) const;

};

_DRAWING_END


#endif // _MIRROR_H

