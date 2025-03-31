#pragma once


#ifndef _PNG_IMAGE_H
#define _PNG_IMAGE_H

#include <png.h>
#include <string>

#include "color.h"
#include "point.h"

_PNG_BEGIN

class Image
{
protected:
    png_structp _png_read_ptr;
    png_infop _info_read_ptr;
    
    png_bytepp _rows;
    png_byte _channels;

    std::size_t _width;
    std::size_t _height;
    
    png_byte _color_type;
    png_byte _bit_depth;
    png_byte _interlace_type;
    png_byte _compression_type;
    png_byte _filter_type;

public:
    explicit Image(const std::string &filename = "");

    void load(const std::string &filename);
    void save(const std::string &filename);

    Color pixel(const drawing::Point &_p) const;
    Color pixel(const drawing::Point &_p, const Color &color);

    std::size_t width() const noexcept;
    std::size_t height() const noexcept;

    ~Image();

protected:
    void _clear_read_data();

    void _check_png(FILE* file) const;

};


_PNG_END


#endif // _PNG_IMAGE_H

