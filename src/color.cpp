#include "color.h"


_PNG_BEGIN

Color::Color(std::size_t _r, std::size_t _g, std::size_t _b, std::size_t _a)
{
    this->r(_r);
    this->g(_g);
    this->b(_b);
    this->a(_a);

}

Color::Color(std::size_t _r, std::size_t _g, std::size_t _b)
    : Color(_r, _g, _b, 255)
{    }

REALIZE_GETTER_COLOR_CHANNEL(r)
REALIZE_GETTER_COLOR_CHANNEL(g)
REALIZE_GETTER_COLOR_CHANNEL(b)
REALIZE_GETTER_COLOR_CHANNEL(a)


REALIZE_SETTER_COLOR_CHANNEL(r)
REALIZE_SETTER_COLOR_CHANNEL(g)
REALIZE_SETTER_COLOR_CHANNEL(b)
REALIZE_SETTER_COLOR_CHANNEL(a)

_PNG_END

