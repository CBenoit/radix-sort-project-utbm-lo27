/*
* @Author: Jérôme BOULMIER
* @Date:   2015-04-23 18:53:55
* @Last Modified by:   Jérôme BOULMIER
* @Last Modified time: 2015-04-28 13:13:35
*/

#include <getch.h>
#include <termios.h>
#include <stdio.h>

static struct termios old, new;

void initTerminal(int echo)
{
    tcgetattr(0, &old);
    new = old;
    new.c_lflag &= (unsigned int)~ICANON;
    new.c_lflag &= echo ? (unsigned int)ECHO : (unsigned int)~ECHO;
    tcsetattr(0, TCSANOW, &new);
}

void resetTerminal()
{
    tcsetattr(0, TCSANOW, &old);
}

char getch_(int echo)
{
    char ch;
    initTerminal(echo);
    ch = (char)getchar();
    resetTerminal();
    return ch;
}

char getch()
{
    return getch_(0);
}

char getche()
{
    return getch_(1);
}
