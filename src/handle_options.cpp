#include "handle_options.hpp"


namespace handleopt
{

objects::Point
_handle_point(const std::string vals)
{
    std::size_t pos_pt = vals.find('.');

    if (pos_pt == std::string::npos)
    {
        std::cerr << "Error: invalid point" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    return objects::Point(
        std::stoi(vals.substr(0, pos_pt)),
        std::stoi(vals.substr(pos_pt+1))
    );

}


bool
_is_valid_color(std::uint16_t _x)
{ return _x >= 0 && _x <= 255; }

objects::RGB
_handle_rgb(const std::string vals)
{
    std::uint16_t r, g, b;

    std::size_t pos_pt1 = vals.find('.');
    if (pos_pt1 == std::string::npos)
    {
        std::cerr << "Error: invalid color" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    std::size_t pos_pt2 = vals.find('.', pos_pt1+1);
    if (pos_pt2 == std::string::npos)
    {
        std::cerr << "Error: invalid color" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    r = std::stoi(vals.substr(0, pos_pt1));
    g = std::stoi(vals.substr(pos_pt1+1, pos_pt2));
    b = std::stoi(vals.substr(pos_pt2+1));

    if (!_is_valid_color(r) || !_is_valid_color(g) || !_is_valid_color(b))
    {
        std::cerr << "Error: invalid color" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    return objects::RGB(
        r, g, b
    );
    
}


std::uint64_t
_handle_thickness(const std::string vals)
{
    std::int64_t _t = std::stoi(optarg);
    if (_t < 1)
    {
        std::cerr << "Error: invalid thickness" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    return _t;

}


objects::Line 
handle_line(int argc, char **argv)
{
    int opt;
    int option_index = -1;

    bool have_start = false;
    bool have_end = false;
    bool have_color = false;
    bool have_thickness = false;

    objects::Point start;
    objects::Point end;
    objects::RGB color;
    std::uint64_t thickness = 0;

    while ((opt = getopt_long(argc, argv, "s:e:c:t:", line_options, &option_index)) != -1) 
    {
        switch (opt) 
        {
        case 's':
            have_start = true;
            start = _handle_point(optarg);
            break;
        
        case 'e':
            have_end = true;
            end = _handle_point(optarg);
            break;
        
        case 'c':
            have_color = true;
            color = _handle_rgb(optarg);
            break;
        
        case 't':
            have_thickness = true;
            thickness = _handle_thickness(optarg);
            break;

        }
    }

    if (!have_start)
    {
        std::cerr << "Error: the line must have a start point" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    if (!have_end)
    {
        std::cerr << "Error: the line must have an end point" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    if (!have_color)
    {
        std::cerr << "Error: the line must have a color" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    if (!have_thickness)
    {
        std::cerr << "Error: the line must have a thickness" << std::endl;
        std::exit(EXIT_FAILURE);
    }


    return objects::Line(
        start,
        end,
        color,
        thickness
    );
}

};