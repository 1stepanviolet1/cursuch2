#pragma once


#ifndef _OPTIONS_H
#define _OPTIONS_H

#include <cstdint>
#include <iostream>

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

// namespace final
#define _FINAL_BEGIN \
    namespace final  \
    {
#define _FINAL_END } // final


_FINAL_BEGIN

enum exitcode
{
    OK = 40,
    ERROR = 41,
    DEFAULT = 0
};

template<typename T> void 
__exit(int _exitcode, T &&arg)
{
    std::cerr << arg << std::endl;
    std::exit(_exitcode);

}

template<typename T, typename ..._Args> void 
__exit(int _exitcode, T &&arg, _Args&& ..._args)
{
    std::cerr << arg << ' ';
    __exit(_exitcode, std::forward<_Args>(_args)...);

}

template<typename ..._Args> void 
error(_Args ..._args)
{ __exit(exitcode::ERROR, _args...); }

template<typename ..._Args> void 
exit(_Args ..._args)
{ __exit(exitcode::OK, _args...); }

_FINAL_END


#endif // _OPTIONS_H

