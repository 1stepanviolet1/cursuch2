#pragma once 


#ifndef _OBJECTS_HPP
#define _OBJECTS_HPP

#include <cstdint>
#include <png.h>
#include <string>
#include <cstdio>
#include <iostream>

#include "constants.hpp"


namespace obj
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

    const Point & start() const;
    const Point & end() const;
    const RGB & color() const;
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

    const Axis & axis() const;
    const Point & left_up() const;
    const Point & right_down() const;

private:
    Axis _axis;
    Point _left_up;
    Point _right_down;

};


class Pentagram
{
public:
    Pentagram(const Point &_center, std::uint64_t _radius, std::uint64_t _thickness, const RGB &_color);

    Pentagram() : Pentagram(Point(), 0, 0, RGB()) {}

    const Point & center() const;
    std::uint64_t radius() const;
    std::uint64_t thickness() const;
    const RGB & color() const;

private:
    Point _center;
    std::uint64_t _radius;
    std::uint64_t _thickness;
    RGB _color;

};


class PNG
{
private:
    std::string _filename;
    FILE *_fp;
    png_structp _png_rptr;
    png_infop _info_ptr; 

public:
    PNG(const std::string filename);

    void write(std::string output_file);

    png_structp png_ptr() const;
    png_infop info_ptr() const;

    ~PNG();

private:
    FILE * _open_file(std::string filename, std::string mode);
    void _check_png_sig(FILE *_fp);
    
    png_structp _create_read_struct();
    png_structp _create_write_struct();

    png_infop _create_info_struct();

};

};


#endif // _OBJECTS_HPP
