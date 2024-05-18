#include "handle_options.hpp"


namespace handleopt
{

objects::Point
_handle_point(const std::string vals)
{
    std::size_t pos_pt = vals.find('.');

    if (pos_pt == std::string::npos)
    {
        std::cout << "Error: invalid point" << std::endl;
        std::exit(FAILURE_CODE);
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
        std::cout << "Error: invalid color" << std::endl;
        std::exit(FAILURE_CODE);
    }

    std::size_t pos_pt2 = vals.find('.', pos_pt1+1);
    if (pos_pt2 == std::string::npos)
    {
        std::cout << "Error: invalid color" << std::endl;
        std::exit(FAILURE_CODE);
    }

    r = static_cast<std::uint16_t>(std::stoi(vals.substr(0, pos_pt1)));
    g = static_cast<std::uint16_t>(std::stoi(vals.substr(pos_pt1+1, pos_pt2)));
    b = static_cast<std::uint16_t>(std::stoi(vals.substr(pos_pt2+1)));

    if (!_is_valid_color(r) || !_is_valid_color(g) || !_is_valid_color(b))
    {
        std::cout << "Error: invalid color" << std::endl;
        std::exit(FAILURE_CODE);
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
        std::cout << "Error: invalid thickness" << std::endl;
        std::exit(FAILURE_CODE);
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
            start = _handle_point(optarg);
            have_start = true;
            break;
        
        case 'e':
            end = _handle_point(optarg);
            have_end = true;
            break;
        
        case 'c':
            color = _handle_rgb(optarg);
            have_color = true;
            break;
        
        case 't':
            thickness = _handle_thickness(optarg);
            have_thickness = true;
            break;

        }
    }

    if (!have_start)
    {
        std::cout << "Error: the line must have a start point" << std::endl;
        std::exit(FAILURE_CODE);
    }

    if (!have_end)
    {
        std::cout << "Error: the line must have an end point" << std::endl;
        std::exit(FAILURE_CODE);
    }

    if (!have_color)
    {
        std::cout << "Error: the line must have a color" << std::endl;
        std::exit(FAILURE_CODE);
    }

    if (!have_thickness)
    {
        std::cout << "Error: the line must have a thickness" << std::endl;
        std::exit(FAILURE_CODE);
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
        std::cout << "Error: invalid axis" << std::endl;
        std::exit(FAILURE_CODE);
    }

    switch (*vals.data())
    {
    case static_cast<char>(objects::Axis::x):
    case static_cast<char>(objects::Axis::y):
        return static_cast<objects::Axis>(*vals.data());
    
    default:
        std::cout << "Error: invalid axis" << std::endl;
        std::exit(FAILURE_CODE);

    }

}

objects::Mirror 
handle_mirror(int argc, char **argv)
{
    int opt;
    int option_index = -1;

    bool have_axis = false;
    bool have_left_up = false;
    bool have_right_down = false;

    objects::Axis axis;
    objects::Point left_up;
    objects::Point right_down;

    while ((opt = getopt_long(argc, argv, "a:u:d:", mirror_options, &option_index)) != -1) 
    {
        switch (opt) 
        {
        case 'a':
            axis = _handle_axis(optarg);
            have_axis = true;
            break;
        
        case 'u':
            left_up = _handle_point(optarg);
            have_left_up = true;
            break;
        
        case 'd':
            right_down = _handle_point(optarg);
            have_right_down = true;
            break;

        }
    }

    if (!have_axis)
    {
        std::cout << "Error: the mirror must have a axis" << std::endl;
        std::exit(FAILURE_CODE);
    }

    if (!have_left_up)
    {
        std::cout << "Error: the mirror must have a left up point" << std::endl;
        std::exit(FAILURE_CODE);
    }

    if (!have_right_down)
    {
        std::cout << "Error: the mirror must have a right down point" << std::endl;
        std::exit(FAILURE_CODE);
    }

    return objects::Mirror(
        axis,
        left_up,
        right_down
    );

}



std::uint64_t
_handle_radius(const std::string vals)
{
    std::int64_t _r = std::stoi(optarg);
    if (_r < 1)
    {
        std::cout << "Error: invalid radius" << std::endl;
        std::exit(FAILURE_CODE);
    }

    return _r;

}

objects::Pentagram 
handle_pentagram(int argc, char **argv)
{
    int opt;
    int option_index = -1;

    bool have_center = false;
    bool have_radius = false;
    bool have_thickness = false;
    bool have_color = false;

    objects::Point center;
    std::uint64_t radius;
    std::uint64_t thickness;
    objects::RGB color;

    while ((opt = getopt_long(argc, argv, "C:r:h:2:", pentagram_options, &option_index)) != -1) 
    {
        switch (opt) 
        {
        case 'C':
            center = _handle_point(optarg);
            have_center = true;
            break;
        
        case 'r':
            radius = _handle_radius(optarg);
            have_radius = true;
            break;
        
        case 'h':
            thickness = _handle_thickness(optarg);
            have_thickness = true;
            break;

        case '2':
            color = _handle_rgb(optarg);
            have_color = true;
            break;
        }
    }

    if (!have_center)
    {
        std::cout << "Error: the pentagram must have a center" << std::endl;
        std::exit(FAILURE_CODE);
    }

    if (!have_radius)
    {
        std::cout << "Error: the pentagram must have a radius" << std::endl;
        std::exit(FAILURE_CODE);
    }

    if (!have_thickness)
    {
        std::cout << "Error: the pentagram must have a thickness" << std::endl;
        std::exit(FAILURE_CODE);
    }

    if (!have_color)
    {
        std::cout << "Error: the pentagram must have a color" << std::endl;
        std::exit(FAILURE_CODE);
    }

    return objects::Pentagram(
        center,
        radius,
        thickness,
        color
    );

}

};