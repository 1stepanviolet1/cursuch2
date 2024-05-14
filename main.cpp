#include <iostream>
#include <getopt.h>

#include "handle_options.hpp"
#include "plugs_for_flags.hpp"


int main(int argc, char **argv)
{
    bool drawing_line = false;
    objects::Line line;

    bool drawing_mirror = false;
    objects::Mirror mirror;

    int opt;
    int option_index = -1;

    while ((opt = getopt_long(argc, argv, "lm", handleopt::global_options, &option_index)) != -1) {
        switch (opt) {
        case 'l':
            line = handleopt::handle_line(argc, argv);
            drawing_line = true;
            break;
        
        case 'm':
            mirror = handleopt::handle_mirror(argc, argv);
            drawing_mirror = true;
            break;

        }
    }

    if (drawing_line)
        draw_line(line);

    if (drawing_mirror)
        draw_mirror(mirror);

    return 0;

}
