// general functions used throughout main and games

#include <stdio.h>
#include <stdlib.h>
#include "ansi_escapes.h"
#include "core.h"

// wait for ENTER keypress
// use getchar() to remove \n from previous input from stdin before calling
void waitForEnter()
{
    printf("\n\nPress ENTER to Continue\n");
    do
    {
    } while (getchar() != '\n');
}

// overwrite what is currently displayed on console w/o scrolling
void clearScreenInPlace()
{
    clearScreenToTop();
    moveToPos(1, 1);
}
