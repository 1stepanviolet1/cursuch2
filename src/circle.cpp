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
    
    std::size_t min_x = this->_center.x() - this->_radius >= 0 
               ? this->_center.x() - this->_radius 
               : 0;
    
    std::size_t max_x = this->_center.x() + this->_radius < _image.width()
               ? this->_center.x() + this->_radius
               : _image.width() - 1;

    std::size_t min_y = this->_center.y() - this->_radius >= 0
               ? this->_center.y() - this->_radius
               : 0;

    std::size_t max_y = this->_center.y() + this->_radius < _image.height()
               ? this->_center.y() + this->_radius
               : _image.height() - 1;

    std::int64_t __dx, __dy;
    for (std::size_t y = min_y; y <= max_y; y++)
        for (std::size_t x = min_x; x <= max_x; x++)
        {
            __dx = x - this->_center.x();
            __dy = y - this->_center.y();

            if (
                std::pow(__dx, 2) 
                + std::pow(__dy, 2) 
                <= std::pow(this->_radius, 2)
            ) _image.pixel({x, y}, this->_color);
        }

}

_DRAWING_END

