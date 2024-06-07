#include "utils.h"

void clearScreen() {
    #if defined _WIN32
        system("cls");
    #elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        system("clear");
        // std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences
    #elif defined(__APPLE__)
        system("clear");
    #endif
}