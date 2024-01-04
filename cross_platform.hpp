#ifndef CROSS_PLATFORM_HPP_INCLUDED
#define CROSS_PLATFORM_HPP_INCLUDED

#include <iostream>
#include <stdlib.h>

#ifdef __WIN32__

#include <windows.h>
#include <system.h>

#endif // __WIN32__

#ifdef __linux__

#include <unistd.h>
#include <termios.h>

#endif // __linux__

void clear_output();
void pause_screen();

#endif // CROSS_PLATFORM_HPP_INCLUDED