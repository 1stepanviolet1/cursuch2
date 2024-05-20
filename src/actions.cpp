#include "actions.hpp"


namespace act
{

template <typename T>
void
_swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

std::vector<obj::Point> 
_calc_point_of_Bresenham(const obj::Point p0, const obj::Point p1) 
{
    std::int64_t x0 = p0.x();
    std::int64_t y0 = p0.y();
    std::int64_t x1 = p1.x();
    std::int64_t y1 = p1.y();

    std::vector<obj::Point> linePoints;

    std::int64_t dx = std::abs(x1 - x0);
    std::int64_t dy = std::abs(y1 - y0);
    std::int64_t sx = (x0 < x1) ? 1 : -1;
    std::int64_t sy = (y0 < y1) ? 1 : -1;
    std::int64_t err = dx - dy;

    while (true) 
    {
        linePoints.push_back({x0, y0});
        if (x0 == x1 && y0 == y1) 
            break;

        std::int64_t e2 = 2 * err;
        if (e2 > -dy) 
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) 
        {
            err += dx;
            y0 += sy;
        }
    }

    return linePoints;
}

std::vector<obj::Point>
_calc_point_of_line(const obj::Point p0, const obj::Point p1, std::int64_t thickness) 
{
    std::int64_t x0 = p0.x();
    std::int64_t y0 = p0.y();
    std::int64_t x1 = p1.x();
    std::int64_t y1 = p1.y();

    std::vector<obj::Point> linePoints;

    // Рисуем основную линию
    std::vector<obj::Point> mainLine = _calc_point_of_Bresenham({x0, y0}, {x1, y1});
    linePoints.insert(linePoints.end(), mainLine.begin(), mainLine.end());

    // Рисуем дополнительные линии с обеих сторон основной линии
    for (std::int64_t i = 1; i <= thickness / 2; ++i) 
    {
        std::vector<obj::Point> offsetLine1 = _calc_point_of_Bresenham({x0 + i, y0}, {x1 + i, y1});
        std::vector<obj::Point> offsetLine2 = _calc_point_of_Bresenham({x0 - i, y0}, {x1 - i, y1});
        linePoints.insert(linePoints.end(), offsetLine1.begin(), offsetLine1.end());
        linePoints.insert(linePoints.end(), offsetLine2.begin(), offsetLine2.end());
    }

    // Удаляем дубликаты точек
    std::sort(linePoints.begin(), 
              linePoints.end(), 
              [] (const obj::Point &a, const obj::Point &b) 
              { return a.x() < b.x() || (a.x() == b.x() && a.y() < b.y()); });

    linePoints.erase(
        std::unique(linePoints.begin(), 
                    linePoints.end(), 
                    [] (const obj::Point &a, const obj::Point &b) 
                    { return a.x() == b.x() && a.y() == b.y(); }), 
        linePoints.end());

    return linePoints;

}

void 
draw_line(const obj::PNG &_png, const obj::Line &_line)
{
    std::int64_t width = png_get_image_width(_png.png_ptr(), _png.info_ptr());
    std::int64_t height = png_get_image_height(_png.png_ptr(), _png.info_ptr());

    png_bytep *row_pointers = png_get_rows(_png.png_ptr(), _png.info_ptr());

    png_byte color[4] = {
        _line.color().r(),
        _line.color().g(),
        _line.color().b(),
        255
    };

    std::int64_t thickness = _line.thickness();

    auto points_of_line = _calc_point_of_line(_line.start(), _line.end(), thickness);

    png_bytep px;
    for (const auto &pt : points_of_line)
    {
        if (pt.x() < 0 || pt.x() >= width)
            continue;
        if (pt.y() < 0 || pt.y() >= height)
            continue;
        
        px = &(row_pointers[pt.y()][pt.x()*4]);

        for (std::size_t c = 0; c < 4; ++c)
            px[c] = color[c];

    }

}

};
