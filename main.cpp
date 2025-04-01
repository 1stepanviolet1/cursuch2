#include "image.h"
#include "circle_builder.h"


int main(int argc, char **argv)
{
    png::Image image("./data/image.png");

    drawing::CircleBuilder circle_builder;
    circle_builder.setup_center({500, 500})
                  .setup_radius(100)
                  .setup_color(png::Color(0, 255, 0));

    circle_builder.get()->draw(image);

    image.save("./data/output.png");

    return 0;

}
