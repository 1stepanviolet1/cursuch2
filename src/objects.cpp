#include "objects.hpp"


namespace obj
{

std::uint16_t 
RGB::r() const
{ return this->_r; }

std::uint16_t 
RGB::g() const
{ return this->_g; }

std::uint16_t 
RGB::b() const
{ return this->_b; }



std::int64_t
Point::x() const
{ return this->_x; }

std::int64_t
Point::y() const
{ return this->_y; }



Line::Line(const Point &_start, const Point &_end, const RGB &_color, std::uint64_t _thickness)
{
    this->_start = _start;
    this->_end = _end;
    this->_color = _color;
    this->_thickness = _thickness;

}

const Point &
Line::start() const
{ return this->_start; }

const Point &
Line::end() const
{ return this->_end; }

const RGB &
Line::color() const
{ return this->_color; }

std::uint64_t
Line::thickness() const
{ return this->_thickness; }



Mirror::Mirror(const Axis &_axis, const Point &_left_up, const Point &_right_down)
{
    this->_axis = _axis;
    this->_left_up = _left_up;
    this->_right_down = _right_down;

}

const Axis &
Mirror::axis() const
{ return this->_axis; }

const Point &
Mirror::left_up() const
{ return this->_left_up; }

const Point &
Mirror::right_down() const
{ return this->_right_down; }



Pentagram::Pentagram(const Point &_center, 
                     std::uint64_t _radius, 
                     std::uint64_t _thickness, 
                     const RGB &_color)
{
    this->_center = _center;
    this->_radius = _radius;
    this->_thickness = _thickness;
    this->_color = _color;

}


const Point & 
Pentagram::center() const
{ return this->_center; }

std::uint64_t 
Pentagram::radius() const
{ return this->_radius; }

std::uint64_t 
Pentagram::thickness() const
{ return this->_thickness; }

const RGB & 
Pentagram::color() const
{ return this->_color; }

};
