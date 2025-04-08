#include "image.h"
#include "draw.h"
#include "options_parser.h"


int main(int argc, char **argv)
{
    sys::options_parser parser;

    try
    {
        parser.parse(argc, argv);
    } catch(const std::invalid_argument& err)
    {
        sys::error("Error:", err.what());
    }

    drawing::Builder *builder;

    switch (parser.type)
    {
    case drawing::figure_type::line:
        drawing::LineBuilder *line_builder;
        try { line_builder = new drawing::LineBuilder; }
        catch(const std::bad_alloc& err)
        { sys::error(err.what()); }
        
        try
        {
            (*line_builder).setup_color(parser.color)
                           .setup_thickness(parser.thickness)
                           .setup_start(parser.start)
                           .setup_end(parser.end);
        }
        catch(const std::invalid_argument& err)
        {
            sys::error("Error:", err.what());
        }
        
        break;
    
    case drawing::figure_type::mirror:
        try
        {
            /* code */
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        break;

    case drawing::figure_type::pentagram:
        try
        {
            /* code */
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        break;

    case drawing::figure_type::null:
        sys::error("Error: bad figure_type");
    
    default:
        sys::error("invalid situation: unknown figure_type");

    }

    return sys::exitcode::DEFAULT;

}
