#pragma once


#ifndef _OPTIONS_H
#define _OPTIONS_H

#include <cstdint>

// namespace png
#define _PNG_BEGIN \
    namespace png  \
    {
#define _PNG_END } // png

// namespace drawing
#define _DRAWING_BEGIN \
    namespace drawing  \
    {
#define _DRAWING_END } // drawing

// status codes
enum exitcode
{
    OK = 40,
    ERROR = 41
};


#endif // _OPTIONS_H

