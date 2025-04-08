#include "pentagram.h"


_DRAWING_BEGIN

Pentagram::Pentagram()
    : _center({0, 0}), _radius(0), _thickness(0), _color(png::Color())
{    }

void
Pentagram::draw(png::Image &_image) const
{
    this->draw_ring(_image);

    this->draw_star(_image);

}

void
Pentagram::draw_ring(png::Image &_image) const
{
    if (!this->_thickness || !this->_radius)
        throw std::invalid_argument("bad data for Pentagram");

    std::int64_t __x = this->_center.x();
    std::int64_t __y = this->_center.y();
    std::int64_t __t = this->_thickness;
    std::int64_t r = static_cast<std::int64_t>(this->_radius) - __t / 2;
    std::int64_t R = static_cast<std::int64_t>(this->_radius) + __t / 2;

    std::uint64_t min_x = __x - R >= 0 
                ? __x - R 
                : 0;
    
    std::uint64_t max_x = __x + R < _image.width()
                ? __x + R
                : _image.width() - 1;

    std::uint64_t min_y = __y - R >= 0
                ? __y - R
                : 0;

    std::uint64_t max_y = __y + R < _image.height()
                ? __y + R
                : _image.height() - 1;
    
    std::int64_t __dx, __dy;
    for (std::int64_t y = min_y; y <= max_y; y++)
        for (std::int64_t x = min_x; x <= max_x; x++)
        {
            __dx = x - __x;
            __dy = y - __y;

            if (
                   std::pow(__dx, 2) + std::pow(__dy, 2) <= std::pow(R, 2)
                && std::pow(__dx, 2) + std::pow(__dy, 2) >= std::pow(r, 2)
            ) _image.pixel({
                static_cast<std::uint64_t>(x),
                static_cast<std::uint64_t>(y)
            }, this->_color);
        }

}

void
Pentagram::draw_star(png::Image &_image) const
{
    Point p0 = this->__get_next_star_peak();
    Point p1 = this->__get_next_star_peak();
    Point p2 = this->__get_next_star_peak();
    Point p3 = this->__get_next_star_peak();
    Point p4 = this->__get_next_star_peak();

    LineBuilder line_builder;
    line_builder.setup_color(this->_color)
                .setup_thickness(this->_thickness);
    
    line_builder.setup_start(p0)
                .setup_end(p2);
    line_builder.get()->draw(_image); // p0 -> p2
    
    line_builder.setup_end(p3);
    line_builder.get()->draw(_image); // p0 -> p3
    
    line_builder.setup_start(p1);
    line_builder.get()->draw(_image); // p1 -> p3
    
    line_builder.setup_end(p4);
    line_builder.get()->draw(_image); // p1 -> p4
    
    line_builder.setup_start(p2);
    line_builder.get()->draw(_image); // p2 -> p4

}

Point 
Pentagram::__get_next_star_peak() const
{
    static std::uint64_t i = 0;
    long double offset = (2 * PI / 5) * ((i++) % 5);
    std::int64_t __x = this->_center.x();
    std::int64_t __y = this->_center.y();

    return Point(
        __x + static_cast<std::int64_t>(this->_radius * std::sin(offset)),
        __y - static_cast<std::int64_t>(this->_radius * std::cos(offset))
    );

}

_DRAWING_END

