#include "image.h"
#include "draw.h"
#include "options_parser.h"


int main(int argc, char **argv)
{
    // PARSE
    sys::options_parser parser;

    try
    {
        parser.parse(argc, argv);
    } 
    catch(const std::invalid_argument& err)
    {
        sys::error("Error:", err.what());
    }

    // !PARSE


    if (parser.is_help)
    {
        sys::print_author_info();
        sys::print_help_info();
        sys::exit();
    }


    // READ IMAGE

    png::Image image;
    
    try
    {
        image.load(parser.input);
    } 
    catch(const std::exception& err)
    {
        sys::error("Error:", err.what());
    }

    // !READ IMAGE
    

    if (parser.is_info)
        sys::exit("Image", parser.input, 
                  "has width:", image.width(),
                  "height:", image.height());


    // SETUP FIGURE

    drawing::Builder *builder = nullptr;

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

        builder = line_builder;
        break;
    
    case drawing::figure_type::mirror:

        drawing::MirrorBuilder *mirror_builder;

        try { mirror_builder = new drawing::MirrorBuilder; }
        catch(const std::bad_alloc& err)
        { sys::error(err.what()); }
        
        try
        {
            (*mirror_builder).setup_axis(parser.axis)
                             .setup_left_up(parser.left_up)
                             .setup_right_down(parser.right_down);
        }
        catch(const std::invalid_argument& err)
        {
            sys::error("Error:", err.what());
        }

        builder = mirror_builder;
        break;

    case drawing::figure_type::pentagram:
        
        drawing::PentagramBuilder *pentagram_builder;

        try { pentagram_builder = new drawing::PentagramBuilder; }
        catch(const std::bad_alloc& err)
        { sys::error(err.what()); }
        
        try
        {
            (*pentagram_builder).setup_color(parser.color)
                                .setup_thickness(parser.thickness)
                                .setup_center(parser.center)
                                .setup_radius(parser.radius);
                           
        }
        catch(const std::invalid_argument& err)
        {
            sys::error("Error:", err.what());
        }

        builder = pentagram_builder;
        break;

    case drawing::figure_type::null:
        sys::error("Error: bad figure_type");
    
    default:
        sys::error("invalid situation: unknown figure_type");

    }

    // !SETUP FIGURE


    if (!builder) sys::error("invalid situation: bad builder");


    // DRAW FIGURE

    try
    {
        builder->get()->draw(image);
    }
    catch(const std::invalid_argument& err)
    {
        sys::error("Error:", err.what());
    }

    // !DRAW FIGURE


    // WRITE IMAGE

    try
    {
        image.save(parser.output);
    }
    catch(const std::invalid_argument& err)
    {
        sys::error("Error:", err.what());
    }

    // !WRITE IMAGE


    return sys::exitcode::DEFAULT;

}
