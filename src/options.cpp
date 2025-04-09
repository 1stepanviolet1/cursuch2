#include "options.h"


_SYS_BEGIN

void
print_help_info()
{
    std::cout << "--help, -h: get help info" << std::endl;
	std::cout << "--info, -I: get file info" << std::endl;
	std::cout << "--input, -i: input filename" << std::endl;
	std::cout << "--output, -o: output filename" << std::endl;
	std::cout << "--line, -L: draw line" << std::endl;
	std::cout << "--mirror, -M: draw mirror" << std::endl;
	std::cout << "--pentagram, -P: draw pentagram" << std::endl;
	std::cout << "--start, -s: start coords(x.y), for line" << std::endl;
	std::cout << "--end, -e: end coords(x.y) for line" << std::endl;
	std::cout << "--color, -C: color for line or petagram'" << std::endl;
	std::cout << "--thickness, -t: thickness for line or pentagram" << std::endl;
	std::cout << "--axis, -a: axis for mirror" << std::endl;
	std::cout << "--left_up, l: left up coords(x.y) for mirror" << std::endl;
	std::cout << "--right_down, -r: right down coords(x.y) for mirror" << std::endl;
	std::cout << "--center, -c: center coords(x, y) for pentagram" << std::endl;
    std::cout << "--radius, -R: radius for pentagram" << std::endl;
}

void 
print_author_info()
{ std::cout << "Course work for option 4.20, created by Stepan Ivanov." << std::endl; }

_SYS_END

