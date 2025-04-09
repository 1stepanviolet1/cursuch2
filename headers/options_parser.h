#pragma once


#ifndef _OPTIONS_PARSER_H
#define _OPTIONS_PARSER_H

#include <getopt.h>
#include <sstream>
#include <algorithm>

#include "draw.h"

_SYS_BEGIN

constexpr const char *options = "LMPs:e:C:t:a:l:r:c:R:hIi:o:";

constexpr const struct option long_options[] = {
    {"line", no_argument, NULL, 'L'},
    {"mirror", no_argument, NULL, 'M'},
    {"pentagram", no_argument, NULL, 'P'},
    {"start", required_argument, NULL, 's'},
    {"end", required_argument, NULL, 'e'},
    {"color", required_argument, NULL, 'C'},
    {"thickness", required_argument, NULL, 't'},
    {"axis", required_argument, NULL, 'a'},
    {"left_up", required_argument, NULL, 'l'},
    {"right_down", required_argument, NULL, 'r'},
    {"center", required_argument, NULL, 'c'},
    {"radius", required_argument, NULL, 'R'},
    {"help", no_argument, NULL, 'h'},
    {"info", no_argument, NULL, 'I'},
    {"input", required_argument, NULL, 'i'},
    {"output", required_argument, NULL, 'o'}
};

class options_parser
{
public:
    explicit options_parser() 
        : type(drawing::figure_type::null),
          thickness(0),
          axis(drawing::make_axis()),
          radius(0),
          is_help(false),
          is_info(false)
    {    }

    void parse(int argc, char **argv);

    static char sep() noexcept;
    static char sep(char _c) noexcept;

    ~options_parser() noexcept = default;

protected:
    static png::Color __get_color(const std::string &_pttrn);
    static drawing::Point __get_point(const std::string &_pttrn);

public:
    drawing::figure_type type;

    drawing::Point start;
    drawing::Point end;

    png::Color color;
    std::size_t thickness;

    drawing::Axis axis;
    drawing::Point left_up;
    drawing::Point right_down;

    drawing::Point center;
    std::uint64_t radius;

    bool is_help;
    bool is_info;

    std::string input;
    std::string output;

private:
    static char _sep;

};

_SYS_END


#endif // _OPTIONS_PARSER_H

