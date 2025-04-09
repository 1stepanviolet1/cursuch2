#include "circle.h"


_DRAWING_BEGIN

Circle::Circle()
    : _center({0, 0}), _radius(0), _color(png::Color())
{    }

void
Circle::draw(png::Image &_image) const
{
    if (!this->_radius)
        throw std::invalid_argument("bad data for Circle");
    
    std::int64_t __x = this->_center.x();
    std::int64_t __y = this->_center.y();
    std::int64_t __r = this->_radius;

    std::uint64_t min_x = __x - __r >= 0 
               ? __x - __r 
               : 0;
    
    std::uint64_t max_x = __x + __r < _image.width()
               ? __x + __r
               : _image.width() - 1;

    std::uint64_t min_y = __y - __r >= 0
               ? __y - __r
               : 0;

    std::uint64_t max_y = __y + __r < _image.height()
               ? __y + __r
               : _image.height() - 1;

    std::int64_t __dx, __dy;
    for (std::int64_t y = min_y; y <= max_y; y++)
        for (std::int64_t x = min_x; x <= max_x; x++)
        {
            __dx = x - __x;
            __dy = y - __y;

            if (
                std::pow(__dx, 2) + std::pow(__dy, 2) <= std::pow(__r, 2)
            ) _image.pixel({x, y}, this->_color);
        }

}

_DRAWING_END

