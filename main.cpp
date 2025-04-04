#include "image.h"
#include "line_builder.h"


int main(int argc, char **argv)
{
    png::Image image("./data/image.png");

    drawing::LineBuilder builder;
    builder.setup_color(png::Color(200, 0, 200))
           .setup_thickness(50)
           .setup_start({700, 800})
           .setup_end({900, 600});

    builder.get()->draw(image);

    image.save("./data/output.png");

    return final::exitcode::DEFAULT;

}
