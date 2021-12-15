#ifndef __ANSI_ESCAPES_H__
#define __ANSI_ESCAPES_H__

// integer values used with escape sequence to set colors
enum Colors
{
    RESET_COLOR,
    BLACK_TXT = 30,
    RED_TXT,
    GREEN_TXT,
    YELLOW_TXT,
    BLUE_TXT,
    MAGENTA_TXT,
    CYAN_TXT,
    WHITE_TXT,

    BLACK_BKG = 40,
    RED_BKG,
    GREEN_BKG,
    YELLOW_BKG,
    BLUE_BKG,
    MAGENTA_BKG,
    CYAN_BKG,
    WHITE_BKG
};

// integer values used with escape sequence to clear console lines
enum ClearCodes
{
    CLEAR_FROM_CURSOR_TO_END,
    CLEAR_FROM_CURSOR_TO_BEGIN,
    CLEAR_ALL
};

// display text with various colors
void blackTxt(char text[]);
void redTxt(char text[]);
void greenTxt(char text[]);
void yellowTxt(char text[]);
void blueTxt(char text[]);
void magentaTxt(char text[]);
void cyanTxt(char text[]);
void whiteTxt(char text[]);
void coloredTxt(char text[], int color);

// set background to various colors
void blackBkg();
void redBkg();
void greenBkg();
void yellowkBkg();
void blueBkg();
void magentaBkg();
void cyanBkg();
void whiteBkg();

// reset console colors
void restoreConsole();

// various methods for clearing console lines
void clearScreen();
void clearScreenToBottom();
void clearScreenToTop();
void clearLine();
void clearLineToRight();
void clearLineToLeft();

// move cursor to various positions in console
void moveUp(int position);
void moveDown(int position);
void moveRight(int position);
void moveLeft(int position);
void moveToPos(int row, int col);

#endif