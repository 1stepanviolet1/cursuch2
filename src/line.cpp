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
    
    std::int64_t __s_x = this->_start_point.x();
    std::int64_t __s_y = this->_start_point.y();
    std::int64_t __e_x = this->_end_point.x();
    std::int64_t __e_y = this->_end_point.y();
    
    std::int8_t sx =  __s_x < __e_x ? 1 : -1;
    std::int8_t sy = __s_y < __e_y ? 1 : -1;

    std::int64_t dx = std::abs(__e_x - __s_x);
    std::int64_t dy = std::abs(__e_y - __s_y);

    std::int64_t err = dx - dy;
    std::int64_t double_err;

    CircleBuilder circle_builder;
    circle_builder.setup_color(this->_color);
    if (this->_thickness > 1) 
        circle_builder.setup_radius(this->_thickness / 2);

    std::vector<Point> line_points;
    while (true) 
    {
        if (__s_x >= 0 && __s_x < _image.width() && __s_y >= 0 && __s_y < _image.height())
            line_points.push_back({__s_x, __s_y});

        if (__s_x == __e_x && __s_y == __e_y)
            break;

        double_err = 2 * err;

        if (double_err > -dy)
        {
            err -= dy;
            __s_x += sx;
        }

        if (double_err < dx)
        {
            err += dx;
            __s_y += sy;
        }

    }

    if (this->_thickness == 1) 
    {
        for (const auto &_pt : line_points)
            _image.pixel(_pt, this->_color);
    } else 
    {
        for (const auto &_pt : line_points)
        {
            circle_builder.setup_center(_pt);
            circle_builder.get()->draw(_image);
        }
    }

}

_DRAWING_END

