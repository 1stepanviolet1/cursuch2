#include "options_parser.h"


_SYS_BEGIN

char options_parser::_sep = '.';

char
options_parser::sep() noexcept
{ return _sep; }

char
options_parser::sep(char _c) noexcept
{ return _sep = _c; }


void 
options_parser::parse(int argc, char **argv)
{
    int opt;
    int option_index;

    while((opt = getopt_long(argc, argv, options, long_options, &option_index)) != -1)
    {
        switch(opt)
        {
            case 'L':{
                this->type = drawing::figure_type::line;
                break;}
            
            case 'M':{
                this->type = drawing::figure_type::mirror;
                break;}

            case 'P':{
                this->type = drawing::figure_type::pentagram;
                break;}

            case 's':{
                this->start = __get_point(optarg);
                break;}
            
            case 'e':{
                this->end = __get_point(optarg);
                break;}
            
            case 'C':{
                this->color = __get_color(optarg);
                break;}
            
            case 't':{
                std::int64_t thickness = std::stoi(optarg);
                if (thickness <= 0)
                    throw std::invalid_argument("bad thickness");

                this->thickness = thickness;
                break;}

            case 'a':{
                this->axis = drawing::make_axis(*optarg);
                if (this->axis == drawing::make_axis())
                    throw std::invalid_argument("bad axis");

                break;}
            
            case 'l':{
                this->left_up = __get_point(optarg);
                break;}
            
            case 'r':{
                this->right_down = __get_point(optarg);
                break;}

            case 'c':{
                this->center = __get_point(optarg);
                break;}
            
            case 'R':{
                std::int64_t radius = std::stoi(optarg);
                if (radius <= 0)
                    throw std::invalid_argument("bad radius");

                this->radius = radius;
                break;}

            case 'h':{
                this->is_help = true;
                return;}
            
            case 'I':{
                this->is_info = true;
                break;}
            
            case 'i':{
                this->input = optarg;
                break;}
            
            case 'o':{
                this->output = optarg;
                break;}
            
            case '?':
            default:
                throw std::invalid_argument("bad option");
            
        }
    }
}

png::Color
options_parser::__get_color(const std::string &_pttrn)
{
    std::stringstream ss(_pttrn);
    std::string token;
    png::Color color;

    std::getline(ss, token, sep());
    color.r(std::stoi(token));

    std::getline(ss, token, sep());
    color.g(std::stoi(token));

    std::getline(ss, token, sep());
    color.b(std::stoi(token));

    return color;

}

drawing::Point
options_parser::__get_point(const std::string &_pttrn)
{
    std::stringstream ss(_pttrn);
    std::string token;

    std::getline(ss, token, sep());
    std::uint64_t x = std::stoi(token);

    std::getline(ss, token, sep());
    std::uint64_t y = std::stoi(token);

    return drawing::Point(x, y);

}

_SYS_END

