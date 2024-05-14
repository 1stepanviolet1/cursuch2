#include "plugs_for_flags.hpp"


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
