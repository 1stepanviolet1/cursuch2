#pragma once 


#ifndef _HANDLE_OPTIONS_HPP
#define _HANDLE_OPTIONS_HPP

#include <getopt.h>
#include <cstdint>
#include <string>
#include <iostream>
#include <cstring>
#include <unordered_map>
#include <functional>

#include "objects.hpp"
#include "constants.hpp"


namespace handleopt
{

constexpr struct option default_options[] = {
    {"help", no_argument, 0, 'h'},
    {"info", no_argument, 0, 311},
    {"input", required_argument, 0, 'i'},
    {"output", required_argument, 0, 'o'},
    {0, 0, 0, 0}
};

constexpr struct option global_options[] = {
    {"line", no_argument, 0, 308},
    {"mirror", no_argument, 0, 309},
    {"pentagram", no_argument, 0, 310},
    {0, 0, 0, 0}
};

constexpr struct option line_options[] = {
    {"start", required_argument, 0, 's'},
    {"end", required_argument, 0, 'e'},
    {"color", required_argument, 0, 300},
    {"thickness", required_argument, 0, 301},
    {0, 0, 0, 0}
};

constexpr struct option mirror_options[] = {
    {"axis", required_argument, 0, 302},
    {"left_up", required_argument, 0, 303},
    {"right_down", required_argument, 0, 304},
    {0, 0, 0, 0}
};

constexpr struct option pentagram_options[] = {
    {"center", required_argument, 0, 305},
    {"radius", required_argument, 0, 'r'},
    {"thickness", required_argument, 0, 306},
    {"color", required_argument, 0, 307},
    {0, 0, 0, 0}
};

obj::Line * handle_line(int argc, char **argv);

obj::Mirror * handle_mirror(int argc, char **argv);

obj::Pentagram * handle_pentagram(int argc, char **argv);

static std::unordered_map<obj::Figure::types, std::function<obj::Figure*(int, char**)>> handle_map = {
    {obj::Figure::types::line, handle_line},
    {obj::Figure::types::mirror, handle_mirror},
    {obj::Figure::types::pentagram, handle_pentagram}
};

static struct def_opt
{
    bool have_help = false;
    bool have_info = false;
    const char *input = nullptr;
    const char *output = nullptr;
} def_opt;

obj::Figure * handle_options(int argc, char **argv);

};


#endif // _HANDLE_OPTIONS_HPP
