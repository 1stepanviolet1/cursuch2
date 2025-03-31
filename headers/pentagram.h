#pragma once


#ifndef _PENTAGRAM_H
#define _PENTAGRAM_H

#include "figure.h"
#include "builder.h"

_DRAWING_BEGIN

class Pentagram : public Figure
{
    friend class BUILDER(Pentagram);

public:
    Pentagram();

    void draw(png::Image &_image) const override;

    ~Pentagram() override = default;

private:
    Point _center;
    std::size_t _radius;
    std::size_t _thickness;
    png::Color _color;

};

_DRAWING_END


#endif // _PENTAGRAM_H

