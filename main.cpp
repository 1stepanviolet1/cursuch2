#include "image.h"
#include "draw.h"


int main(int argc, char **argv)
{
    png::Image image("./data/image.png");

    drawing::PentagramBuilder builder;

    builder.setup_center({500, 500})
           .setup_color(png::Color(255, 255, 0))
           .setup_radius(200)
           .setup_thickness(50);

    // builder.setup_axis('x')
    //        .setup_left_up({500, 500})
    //        .setup_right_down({1100, 1100});

    // builder.setup_color(png::Color(0, 255, 0))
    //        .setup_center({1000, 1000})
    //        .setup_radius(50);

    builder.get()->draw(image);

    image.save("./data/output.png");

    return sys::exitcode::DEFAULT;

}
