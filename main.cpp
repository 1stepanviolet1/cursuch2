#include "image.h"
#include "circle_builder.h"


int main(int argc, char **argv)
{
    png::Image image("./data/image.png");

    drawing::CircleBuilder circle_builder;
    circle_builder.setup_center({100, 100})
                  .setup_radius(50)
                  .setup_color(png::Color(255, 0, 0));

    circle_builder.get()->draw(image);

    image.save("./data/output.png");

    return 0;

}
