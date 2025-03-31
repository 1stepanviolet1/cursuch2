#include "line.h"


_DRAWING_BEGIN

Line::Line()
    : _start_point({0, 0}), _end_point({0, 0}), _color(png::Color()), _thickness(0)
{    }

void
Line::draw(png::Image &_image) const
{
    if (!this->_thickness)
        throw std::invalid_argument("bad data for Line");
    
    

}

_DRAWING_END

