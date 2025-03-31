#include "line.h"


_DRAWING_BEGIN


Line::Line()
    : _start_point({0, 0}), _end_point({0, 0}), _color(png::Color()), _thickness(0)
{    }

void
Line::draw(png::Image &_image) const
{
    throw std::runtime_error("Line::draw");

}

_DRAWING_END

