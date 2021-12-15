// abstractions for various ANSI escape codes

#include <stdio.h>
#include "ansi_escapes.h"

// escape sequence
const char ESCAPE_PREFIX[] = "\x1b[";

// display text with various colors
void blackTxt(char text[])
{
    printf("%s%dm%s", ESCAPE_PREFIX, BLACK_TXT, text);
}

void redTxt(char text[])
{
    printf("%s%dm%s", ESCAPE_PREFIX, RED_TXT, text);
}

void greenTxt(char text[])
{
    printf("%s%dm%s", ESCAPE_PREFIX, GREEN_TXT, text);
}

void yellowTxt(char text[])
{
    printf("%s%dm%s", ESCAPE_PREFIX, YELLOW_TXT, text);
}

void blueTxt(char text[])
{
    printf("%s%dm%s", ESCAPE_PREFIX, BLUE_TXT, text);
}

void magentaTxt(char text[])
{
    printf("%s%dm%s", ESCAPE_PREFIX, MAGENTA_TXT, text);
}

void cyanTxt(char text[])
{
    printf("%s%dm%s", ESCAPE_PREFIX, CYAN_TXT, text);
}

void whiteTxt(char text[])
{
    printf("%s%dm%s", ESCAPE_PREFIX, WHITE_TXT, text);
}

void coloredTxt(char text[], int color)
{
    printf("%s%dm%s", ESCAPE_PREFIX, color, text);
}

// set background to various colors
void blackBkg()
{
    printf("%s%dm", ESCAPE_PREFIX, BLACK_BKG);
}

void redBkg()
{
    printf("%s%dm", ESCAPE_PREFIX, RED_BKG);
}

void greenBkg()
{
    printf("%s%dm", ESCAPE_PREFIX, GREEN_BKG);
}

void yellowkBkg()
{
    printf("%s%dm", ESCAPE_PREFIX, YELLOW_BKG);
}

void blueBkg()
{
    printf("%s%dm", ESCAPE_PREFIX, BLUE_BKG);
}

void magentaBkg()
{
    printf("%s%dm", ESCAPE_PREFIX, MAGENTA_BKG);
}

void cyanBkg()
{
    printf("%s%dm", ESCAPE_PREFIX, CYAN_BKG);
}

void whiteBkg()
{
    printf("%s%dm", ESCAPE_PREFIX, WHITE_BKG);
}

// reset console colors
void restoreConsole()
{
    printf("%s%dm", ESCAPE_PREFIX, RESET_COLOR);
}

// various methods for clearing console lines
void clearScreen()
{
    printf("%s%dJ", ESCAPE_PREFIX, CLEAR_ALL);
}

void clearScreenToBottom()
{
    printf("%s%dJ", ESCAPE_PREFIX, CLEAR_FROM_CURSOR_TO_END);
}

void clearScreenToTop()
{
    printf("%s%dJ", ESCAPE_PREFIX, CLEAR_FROM_CURSOR_TO_BEGIN);
}

void clearLine()
{
    printf("%s%dK", ESCAPE_PREFIX, CLEAR_ALL);
}

void clearLineToRight()
{
    printf("%s%dK", ESCAPE_PREFIX, CLEAR_FROM_CURSOR_TO_END);
}

void clearLineToLeft()
{
    printf("%s%dK", ESCAPE_PREFIX, CLEAR_FROM_CURSOR_TO_BEGIN);
}

// move cursor to various positions in console
void moveUp(int position)
{
    printf("%s%dA", ESCAPE_PREFIX, position);
}

void moveDown(int position)
{
    printf("%s%dB", ESCAPE_PREFIX, position);
}

void moveRight(int position)
{
    printf("%s%dC", ESCAPE_PREFIX, position);
}

void moveLeft(int position)
{
    printf("%s%dD", ESCAPE_PREFIX, position);
}

void moveToPos(int row, int col)
{
    printf("%s%d;%df", ESCAPE_PREFIX, row, col);
}
