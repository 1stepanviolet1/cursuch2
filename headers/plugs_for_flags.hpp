#pragma once 


#ifndef _PLUGS_HPP
#define _PLUGS_HPP

#include <iostream>

#include "objects.hpp"


namespace plug
{
void draw_line(const obj::Line &_line);
void draw_mirror(const obj::Mirror &_mirror);
void draw_pentagram(const obj::Pentagram &_pentagram);
};

#endif // _PLUGS_HPP
