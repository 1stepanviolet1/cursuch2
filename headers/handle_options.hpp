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

static struct option global_options[] = {
    {"line", no_argument, 0, 'l'},
    {"mirror", no_argument, 0, 'm'},
    {0, 0, 0, 0}
};

static struct option line_options[] = {
    {"start", required_argument, 0, 's'},
    {"end", required_argument, 0, 'e'},
    {"color", required_argument, 0, 'c'},
    {"thickness", required_argument, 0, 't'},
    {0, 0, 0, 0}
};

static struct option mirror_options[] = {
    {"axis", required_argument, 0, 'a'},
    {"left_up", required_argument, 0, 'l'},
    {"right_down", required_argument, 0, 'r'},
    {0, 0, 0, 0}
};

objects::Line handle_line(int argc, char **argv);

objects::Mirror handle_mirror(int argc, char **argv);

};


#endif // _HANDLE_OPTIONS_HPP
