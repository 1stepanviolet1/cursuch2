#include "mirror.h"


_DRAWING_BEGIN

Mirror::Mirror()
    : _axis(Axis::X), _left_up({0, 0}), _right_down({0, 0})
{    }

void
Mirror::draw(png::Image &_image) const
{
    throw std::runtime_error("Mirror::draw");

}

_DRAWING_END

