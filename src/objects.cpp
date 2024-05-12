#include "objects.hpp"


namespace objects
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

Point
Line::start() const
{ return this->_start; }

Point
Line::end() const
{ return this->_end; }

RGB
Line::color() const
{ return this->_color; }

std::uint64_t
Line::thickness() const
{ return this->_thickness; }

};
