#include "cross_platform.hpp"

void clear_output()
{
#ifdef __linux__
    system("clear");
#endif
#ifdef __WIN32__
    system("cls");
#endif // __WIN32__
}

void pause_screen()
{
#ifdef __linux__
    system("read -p 'Press Enter to continue...' var");
#endif // __linux__
#ifdef __WIN32__
    system("pause");
#endif // __WIN32__
}
