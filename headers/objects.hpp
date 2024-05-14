#pragma once 


#ifndef _OBJECTS_HPP
#define _OBJECTS_HPP

#include <cstdint>


namespace objects
{

class RGB
{
public:
    RGB(std::uint16_t _r, std::uint16_t _g, std::uint16_t _b)
        : _r(_r), _g(_g), _b(_b) {}
    
    RGB() : RGB(0, 0, 0) {}
    
    std::uint16_t r() const;
    std::uint16_t g() const;
    std::uint16_t b() const;

private:
    std::uint16_t _r;
    std::uint16_t _g;
    std::uint16_t _b;

};


class Point 
{
public:
    Point(std::int64_t _x, std::int64_t _y)
        : _x(_x), _y(_y) {}
    
    Point() : Point(0, 0) {}

    std::int64_t x() const;
    std::int64_t y() const;

private:
    std::int64_t _x;
    std::int64_t _y;

};


class Line
{
public:
    Line(const Point &_start, const Point &_end, const RGB &_color, std::uint64_t _thickness);

    Line() : Line(Point(), Point(), RGB(), 0) {}

    Point start() const;
    Point end() const;
    RGB color() const;
    std::uint64_t thickness() const;

private:
    Point _start;
    Point _end;
    RGB _color;
    std::uint64_t _thickness;

};


enum class Axis : char
{
    unknown = '0',
    x = 'x',
    y = 'y'
};


class Mirror
{
public:
    Mirror(const Axis &_axis, const Point &_left_up, const Point &_right_down);

    Mirror() : Mirror(Axis::unknown, Point(), Point()) {}

    Axis axis() const;
    Point left_up() const;
    Point right_down() const;

private:
    Axis _axis;
    Point _left_up;
    Point _right_down;

};

};


#endif // _OBJECTS_HPP
