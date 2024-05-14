#pragma once 


#ifndef _PLUGS_HPP
#define _PLUGS_HPP

#include <iostream>

#include "objects.hpp"


namespace plug
{
void draw_line(const objects::Line &_line);
void draw_mirror(const objects::Mirror &_mirror);
void draw_pentagram(const objects::Pentagram &_pentagram);
};

#endif // _PLUGS_HPP
