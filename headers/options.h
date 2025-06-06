#pragma once


#ifndef _OPTIONS_H
#define _OPTIONS_H

#include <cstdint>
#include <iostream>
#include <stdexcept>

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

// namespace sys
#define _SYS_BEGIN \
    namespace sys  \
    {
#define _SYS_END } // sys


_SYS_BEGIN

enum exitcode
{
    OK = 40,
    ERROR = 41,
    DEFAULT = 0
};

template<typename T> void 
__exit(int _exitcode, T &&arg)
{
    std::cout << arg << std::endl;
    std::exit(_exitcode);

}

template<typename T, typename ..._Args> void 
__exit(int _exitcode, T &&arg, _Args&& ..._args)
{
    std::cout << arg << ' ';
    __exit(_exitcode, std::forward<_Args>(_args)...);

}

template<typename ..._Args> void 
error(_Args&& ..._args)
{ __exit(exitcode::ERROR, std::forward<_Args>(_args)...); }

template<typename ..._Args> void 
exit(_Args&& ..._args)
{ __exit(exitcode::OK, std::forward<_Args>(_args)...); }

template<typename ..._Args> void 
exit()
{ std::exit(exitcode::OK); }


void print_help_info();
void print_author_info();

_SYS_END


#endif // _OPTIONS_H

