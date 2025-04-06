#include "image.h"
#include "draw.h"


int main(int argc, char **argv)
{
    png::Image image("./data/image.png");

    drawing::MirrorBuilder builder;
    builder.setup_axis('x')
           .setup_left_up({500, 500})
           .setup_right_down({1100, 1100});

    builder.get()->draw(image);

    image.save("./data/output.png");

    return final::exitcode::DEFAULT;

}
