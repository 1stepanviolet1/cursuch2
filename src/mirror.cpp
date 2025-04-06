#include "mirror.h"


_DRAWING_BEGIN

void
Mirror::draw(png::Image &_image) const
{
    if (this->_axis == Axis::null)
        throw std::invalid_argument("bad data for Mirror");
    
    switch (this->_axis)
    {
    case Axis::X:
        return this->__draw_x_mirror(_image);
    
    case Axis::Y:
        return this->__draw_y_mirror(_image);

    default:
        throw std::runtime_error("bad axis (this can't be)");

    }

}

void
Mirror::__draw_x_mirror(png::Image &_image) const
{
    Point _l_u = Point(
        this->_left_up.x() < _image.width()
            ? this->_left_up.x()
            : _image.width() - 1,
        this->_left_up.y() < _image.height()
            ? this->_left_up.y()
            : _image.height() - 1
    );

    Point _r_d = Point(
        this->_right_down.x() < _image.width()
            ? this->_right_down.x()
            : _image.width() - 1,
        this->_right_down.y() < _image.height()
            ? this->_right_down.y()
            : _image.height() - 1
    );

    std::uint64_t _m_x = _l_u.x();
    std::uint64_t _m_y = _r_d.y();
    png::Color temp_color;

    for (std::uint64_t _y = _l_u.y(); _y <= (_l_u.y() + _r_d.y()) / 2; _y++)
    {
        for (std::uint64_t _x = _l_u.x(); _x <= _r_d.x(); _x++)
        {
            temp_color = _image.pixel({_x, _y});
            _image.pixel({_x, _y}, png::Color(_image.pixel({_m_x, _m_y})));
            _image.pixel({_m_x, _m_y}, temp_color);
            _m_x++;

        }

        _m_x = _l_u.x();
        _m_y--;

    }

}

void
Mirror::__draw_y_mirror(png::Image &_image) const
{
    Point _l_u = Point(
        this->_left_up.x() < _image.width()
            ? this->_left_up.x()
            : _image.width() - 1,
        this->_left_up.y() < _image.height()
            ? this->_left_up.y()
            : _image.height() - 1
    );

    Point _r_d = Point(
        this->_right_down.x() < _image.width()
            ? this->_right_down.x()
            : _image.width() - 1,
        this->_right_down.y() < _image.height()
            ? this->_right_down.y()
            : _image.height() - 1
    );

    std::uint64_t _m_x = _r_d.x();
    std::uint64_t _m_y = _l_u.y();
    png::Color temp_color;

    for (std::uint64_t _y = _l_u.y(); _y <= _r_d.y(); _y++)
    {
        for (std::uint64_t _x = _l_u.x(); _x <= (_l_u.x() + _r_d.x()) / 2; _x++)
        {
            temp_color = _image.pixel({_x, _y});
            _image.pixel({_x, _y}, png::Color(_image.pixel({_m_x, _m_y})));
            _image.pixel({_m_x, _m_y}, temp_color);
            _m_x--;

        }

        _m_x = _r_d.x();
        _m_y++;

    }
    
}

_DRAWING_END

