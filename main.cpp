#include "image.h"
#include "line_builder.h"


int main(int argc, char **argv)
{
    png::Image image("./data/image.png");

    drawing::LineBuilder builder;
    builder.setup_color(png::Color(0, 255, 0))
           .setup_thickness(50)
           .setup_start({0, 0})
           .setup_end({500, 500});

    builder.get()->draw(image);

    image.save("./data/output.png");

    return final::exitcode::DEFAULT;

}
