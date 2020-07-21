#include "utils.hpp"

#ifdef WIN32
#include <Windows.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

#include <iostream>

void SetStdinEcho(bool enable)
{
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hStdin, &mode);

    if (!enable)
        mode &= ~ENABLE_ECHO_INPUT;
    else
        mode |= ENABLE_ECHO_INPUT;

    SetConsoleMode(hStdin, mode);
}

std::string getPassword()
{
    SetStdinEcho(false);
    std::string password;
    std::cin >> password;
    SetStdinEcho(true);
    return password;
}