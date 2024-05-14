#pragma once 


#ifndef _HANDLE_OPTIONS_HPP
#define _HANDLE_OPTIONS_HPP

#include <getopt.h>
#include <cstdint>
#include <string>
#include <iostream>

#include "objects.hpp"


namespace handleopt
{

constexpr struct option global_options[] = {
    {"line", no_argument, 0, 'l'},
    {"mirror", no_argument, 0, 'm'},
    {"pentagram", no_argument, 0, 'p'},
    {0, 0, 0, 0}
};

constexpr struct option line_options[] = {
    {"start", required_argument, 0, 's'},
    {"end", required_argument, 0, 'e'},
    {"color", required_argument, 0, 'c'},
    {"thickness", required_argument, 0, 't'},
    {0, 0, 0, 0}
};

constexpr struct option mirror_options[] = {
    {"axis", required_argument, 0, 'a'},
    {"left_up", required_argument, 0, 'u'},
    {"right_down", required_argument, 0, 'd'},
    {0, 0, 0, 0}
};

constexpr struct option pentagram_options[] = {
    {"center", required_argument, 0, 'C'},
    {"radius", required_argument, 0, 'r'},
    {"thickness", required_argument, 0, 'h'},
    {"color", required_argument, 0, '2'},
    {0, 0, 0, 0}
};

objects::Line handle_line(int argc, char **argv);

objects::Mirror handle_mirror(int argc, char **argv);

objects::Pentagram handle_pentagram(int argc, char **argv);

};


#endif // _HANDLE_OPTIONS_HPP
