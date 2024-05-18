#include "actions.hpp"


namespace act
{

void 
draw_line(const obj::PNG &_png, const obj::Line &_line)
{
    std::int64_t width = png_get_image_width(_png.png_ptr(), _png.info_ptr());
    std::int64_t height = png_get_image_height(_png.png_ptr(), _png.info_ptr());

    png_bytep *row_pointers = png_get_rows(_png.png_ptr(), _png.info_ptr());

    png_byte color[3] = {
        static_cast<png_byte>(_line.color().r()),
        static_cast<png_byte>(_line.color().g()),
        static_cast<png_byte>(_line.color().b())
    };

    std::int64_t x0 = _line.start().x();
    std::int64_t y0 = _line.start().y();
    std::int64_t x1 = _line.end().x();
    std::int64_t y1 = _line.end().y();

    std::int64_t thickness = _line.thickness();

    std::int64_t dx = abs(x1 - x0);
    std::int64_t sx = (x0 < x1) ? 1 : -1;
    std::int64_t dy = -abs(y1 - y0);
    std::int64_t sy = (y0 < y1) ? 1 : -1;
    std::int64_t err = dx + dy;

    while (true) 
    {
        for (std::int64_t i = -thickness / 2; i <= thickness / 2; ++i) 
        {
            for (std::int64_t j = -thickness / 2; j <= thickness / 2; ++j) 
            {
                if (x0 + i >= 0 && x0 + i < width && y0 + j >= 0 && y0 + j < height) 
                {
                    png_bytep px = &(row_pointers[y0 + j][x0 + i * 4]);

                    for (std::size_t k = 0; k < 3; ++k) 
                    {
                        px[k] = color[k];
                    }
                }
            }
        }

        if (x0 == x1 && y0 == y1) 
            break;

        int e2 = 2 * err;

        if (e2 >= dy) 
        {
            err += dy;
            x0 += sx;
        }

        if (e2 <= dx) 
        {
            err += dx;
            y0 += sy;
        }
    }
}

};