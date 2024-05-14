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

    r = static_cast<std::uint16_t>(std::stoi(vals.substr(0, pos_pt1)));
    g = static_cast<std::uint16_t>(std::stoi(vals.substr(pos_pt1+1, pos_pt2)));
    b = static_cast<std::uint16_t>(std::stoi(vals.substr(pos_pt2+1)));

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


objects::Axis
_handle_axis(const std::string vals)
{
    if (vals.size() > 1)
    {
        std::cerr << "Error: invalid axis" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    switch (*vals.data())
    {
    case static_cast<char>(objects::Axis::x):
    case static_cast<char>(objects::Axis::y):
        return static_cast<objects::Axis>(*vals.data());
    
    default:
        std::cerr << "Error: invalid axis" << std::endl;
        std::exit(EXIT_FAILURE);

    }

}

objects::Mirror 
handle_mirror(int argc, char **argv)
{
    int opt;
    int option_index;

    bool have_axis = false;
    bool have_left_up = false;
    bool have_right_down = false;

    objects::Axis axis;
    objects::Point left_up;
    objects::Point right_down;

    while ((opt = getopt_long(argc, argv, "a:l:r:", mirror_options, &option_index)) != -1) 
    {
        switch (opt) 
        {
        case 'a':
            have_axis = true;
            axis = _handle_axis(optarg);
            break;
        
        case 'l':
            have_left_up = true;
            left_up = _handle_point(optarg);
            break;
        
        case 'r':
            have_right_down = true;
            right_down = _handle_point(optarg);
            break;

        }
    }

    if (!have_axis)
    {
        std::cerr << "Error: the mirror must have a axis" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    if (!have_left_up)
    {
        std::cerr << "Error: the mirror must have a left up point" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    if (!have_right_down)
    {
        std::cerr << "Error: the mirror must have a right down point" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    return objects::Mirror(
        axis,
        left_up,
        right_down
    );

}

};