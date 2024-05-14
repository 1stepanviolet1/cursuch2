#include "plugs_for_flags.hpp"


namespace plug
{

void 
draw_line(const objects::Line &_line)
{
    std::cout << "Draw line: ";
    std::cout << "start(" << _line.start().x() << ", " << _line.start().y() << ") ";
    std::cout << "end(" << _line.end().x() << ", " << _line.end().y() << ") ";
    std::cout << "color(" << _line.color().r() << ", " << _line.color().g() << ", " << _line.color().b() << ") ";
    std::cout << "thickness(" << _line.thickness() << ")";
    std::cout << std::endl;

}

void 
draw_mirror(const objects::Mirror &_mirror)
{
    std::cout << "Draw mirror: ";
    std::cout << "axis(" << static_cast<char>(_mirror.axis()) << ") ";
    std::cout << "left_up(" << _mirror.left_up().x() << ", " << _mirror.left_up().y() << ") ";
    std::cout << "right_down(" << _mirror.right_down().x() << ", " << _mirror.right_down().y() << ") ";
    std::cout << std::endl;

}

void 
draw_pentagram(const objects::Pentagram &_pentagram)
{
    std::cout << "Draw pentagram: ";
    std::cout << "center(" << _pentagram.center().x() << ", " << _pentagram.center().y() << ") ";
    std::cout << "radius(" << _pentagram.radius() << ") ";
    std::cout << "thickness(" << _pentagram.thickness() << ") ";
    std::cout << "color(" << _pentagram.color().r() << ", " << _pentagram.color().g() << ", " << _pentagram.color().b() << ")";
    std::cout << std::endl;
}

};
