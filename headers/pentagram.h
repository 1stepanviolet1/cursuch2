#pragma once


#ifndef _PENTAGRAM_H
#define _PENTAGRAM_H

#include <cmath>

#include "figure.h"
#include "line_builder.h"

_DRAWING_BEGIN

static long double PI = 3.14159265;

class Pentagram : public Figure
{
    friend class BUILDER(Pentagram);

public:
    Pentagram();

    void draw(png::Image &_image) const override;

    void draw_ring(png::Image &_image) const;
    void draw_star(png::Image &_image) const;

    ~Pentagram() override = default;

private:
    Point _center;
    std::uint64_t _radius;
    std::size_t _thickness;
    png::Color _color;

private:
    Point __get_next_star_peak() const;

};

_DRAWING_END


#endif // _PENTAGRAM_H

