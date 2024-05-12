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
