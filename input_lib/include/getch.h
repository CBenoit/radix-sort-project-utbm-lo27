/*
* @Author: Jérôme BOULMIER
* @Date:   2015-04-28 13:11:43
* @Last Modified by:   Jérôme BOULMIER
* @Last Modified time: 2015-04-28 13:13:20
*/
#ifndef GETCH_H
#define GETCH_H

#include <termios.h>
#include <stdio.h>

void initTerminal(int echo);

void resetTerminal();

char getch_(int echo);

char getch();

char getche();


#endif // GETCH_H
