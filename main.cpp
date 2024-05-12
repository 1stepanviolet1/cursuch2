#include <iostream>
#include <getopt.h>

#include "handle_options.hpp"
#include "plugs_for_flags.hpp"


int main(int argc, char **argv)
{
    bool drawing_line = false;
    objects::Line line;

    int opt;
    int option_index = -1;

    while ((opt = getopt_long(argc, argv, "l", handleopt::global_options, &option_index)) != -1) {
        switch (opt) {
        case 'l':
            drawing_line = true;
            line = handleopt::handle_line(argc, argv);
            break;

        }
    }

    if (drawing_line)
        draw_line(line);

    return 0;

}
