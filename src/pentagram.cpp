#include "pentagram.h"


_DRAWING_BEGIN


Pentagram::Pentagram()
    : _center({0, 0}), _radius(0), _thickness(0), _color(png::Color())
{    }

void
Pentagram::draw(png::Image &_image) const
{
    throw std::runtime_error("Pentagram::draw");

}

_DRAWING_END

