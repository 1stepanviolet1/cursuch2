#include <getopt.h>
#include <memory>

#include "handle_options.hpp"
#include "actions.hpp"

#include "plugs_for_flags.hpp"

int main(int argc, char **argv)
{
    auto figure = std::unique_ptr<obj::Figure>(
        handleopt::handle_options(argc, argv)
    );

    if (figure->figure() == obj::Figure::types::line)
        plug::draw_line(*(obj::Line*)(figure.get()));
    
    else if (figure->figure() == obj::Figure::types::mirror)
        plug::draw_mirror(*(obj::Mirror*)(figure.get()));
    
    else if (figure->figure() == obj::Figure::types::pentagram)
        plug::draw_pentagram(*(obj::Pentagram*)(figure.get()));

    // obj::PNG png(INPUT_FILENAME);

    // png.write(OUTPUT_FILENAME);

    return 0;

}
