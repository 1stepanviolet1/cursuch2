#include "options_parser.h"


_SYS_BEGIN

std::string options_parser::_sep = ".";

const std::string& 
options_parser::sep() noexcept
{ return _sep; }

const std::string& 
options_parser::sep(const std::string& _s) noexcept
{ return _sep = _s; }


void 
options_parser::parse(int argc, char **argv)
{

}

png::Color 
options_parser::__get_color(const std::string &_pttrn)
{
    // std::stringstream ss(_pttrn);
    // std::string token;


}

drawing::Point
options_parser::__get_point(const std::string &_pttrn)
{
    
}

_SYS_END

