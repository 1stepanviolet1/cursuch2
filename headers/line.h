#pragma once


#ifndef _LINE_H
#define _LINE_H

#include <vector>

#include "circle_builder.h"
#include "builder.h"

_DRAWING_BEGIN

class Line : public Figure
{
    friend class BUILDER(Line);

public:
    explicit Line();

    void draw(png::Image &_image) const override;

    ~Line() override = default;

private:
    Point _start_point;
    Point _end_point;
    png::Color _color;
    std::size_t _thickness;

};

_DRAWING_END


#endif // _LINE_H

