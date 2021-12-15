#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "core.h"
#include "hanoi_resources.h"
#include "ansi_escapes.h"

#define DISKS 5    // number of disks
#define MAXLEN 300 // max char buf length

// struct for towers, keeps track of disk on tower
typedef struct
{
    int disks[DISKS], pos;
} tower;

// arrange disks in descending order on left tower
void initialize(tower *t1, tower *t2, tower *t3)
{
    for (int i = 0; i < DISKS; i++)
    {
        t1->disks[i] = i + 1;
        t2->disks[i] = 0;
        t3->disks[i] = 0;
    }
    t1->pos = 0;
    t2->pos = DISKS;
    t3->pos = DISKS;
}

// display welcome message and rules
void displayHanoiWelcome()
{
    const int len = 1200;
    char buf[len];
    clearScreenInPlace();
    snprintf(buf, len, "%s", resources_hanoi_welcome_txt);
    whiteTxt(buf);
    waitForEnter();
    clearScreenInPlace();
    snprintf(buf, len, "%s", resources_hanoi_rules_txt);
    whiteTxt(buf);
    waitForEnter();
}

// get player's move
void getMove(int *from, int *to)
{
    printf("Enter move: ");
    scanf("%d %d", from, to);
    printf("%d -> %d\n", *from, *to);
    // add sleep function
}

// get disk to move
int moveFrom(tower *t)
{
    int disk = t->disks[t->pos];
    t->disks[t->pos] = 0;
    t->pos++;
    return disk;
}

// move disk to another tower
void moveTo(tower *t, int disk)
{
    t->pos--;
    t->disks[t->pos] = disk;
}

// check that player's move follows rules
int validateMove(tower *from, tower *to)
{
    int disk = from->disks[from->pos];
    if ((disk < to->disks[to->pos] || to->pos == DISKS) && from != to)
        return 0;
    return 1;
}

// perform player's move
int moveDisk(tower *t1, tower *t2, tower *t3)
{
    int disk;
    int from, to;
    tower *fromTower, *toTower;

    getMove(&from, &to);

    switch (from)
    {
    case 1:
        fromTower = t1;
        break;
    case 2:
        fromTower = t2;
        break;
    case 3:
        fromTower = t3;
        break;
    default:
        return 1;
    }

    switch (to)
    {
    case 1:
        toTower = t1;
        break;
    case 2:
        toTower = t2;
        break;
    case 3:
        toTower = t3;
        break;
    default:
        return 1;
    }

    if (validateMove(fromTower, toTower) == 0)
    {
        disk = moveFrom(fromTower);
        moveTo(toTower, disk);
        return 0;
    }
    return 1;
}

// check if all disks have been moved to tower 3 in correct order
int checkSolve(tower *t3)
{
    for (int i = 0; i < DISKS; i++)
    {
        if (t3->disks[i] != i + 1)
            return 1;
    }
    return 0;
}

// display top line of disks
void displayDiskTop(tower *t, int n)
{
    int len = t->disks[n];
    if (len == 0)
    {
        whiteTxt("        ||              "); // display rod if no disk present at position n on rod
    }
    else
    {
        // print correct spacing for disk width
        for (int i = 0; i < 9 - len; i++)
            printf(" ");
        for (int i = 0; i < len * 2; i++)
            coloredTxt("-", (len % 6) + RED_TXT); // disks colored red through cyan
        for (int i = 0; i < 9 - len; i++)
            printf(" ");
        printf("      ");
    }
}

// display sides/second line of disks
void displayDiskSides(tower *t, int n)
{
    int len = t->disks[n];
    if (len == 0)
    {
        whiteTxt("        ||              ");
    }
    else
    {
        for (int i = 0; i < 8 - len; i++)
            printf(" ");
        coloredTxt("|", (len % 6) + RED_TXT);
        for (int i = 0; i < len * 2; i++)
            printf(" ");
        coloredTxt("|", (len % 6) + RED_TXT);
        for (int i = 0; i < 8 - len; i++)
            printf(" ");
        printf("      ");
    }
}

// display game state
void updateDisplay(tower *t1, tower *t2, tower *t3)
{
    char buf[MAXLEN];
    clearScreenInPlace();
    snprintf(buf, MAXLEN, "%s\n", resources_tower_top_txt);
    whiteTxt(buf);
    for (int i = 0; i < DISKS; i++)
    {
        displayDiskTop(t1, i);
        displayDiskTop(t2, i);
        displayDiskTop(t3, i);
        whiteTxt("\n");
        displayDiskSides(t1, i);
        displayDiskSides(t2, i);
        displayDiskSides(t3, i);
        whiteTxt("\n");
    }
    snprintf(buf, MAXLEN, "%s\n\n", resources_tower_base_txt);
    whiteTxt(buf);
}

int main()
{
    tower t1, t2, t3;
    int moveCount = 0;

    // setup game
    blackBkg(); // set background to black
    displayHanoiWelcome();
    initialize(&t1, &t2, &t3);
    updateDisplay(&t1, &t2, &t3);

    // play game
    while (checkSolve(&t3) == 1)
    {
        if (moveDisk(&t1, &t2, &t3) == 0)
            moveCount++; // keeps track of player's total valid moves
        else
            printf("Invalid move!\n");
        // add sleep function
        updateDisplay(&t1, &t2, &t3);
    }

    // display message when solved
    printf("Congratulations! You solved the Towers of Hanoi in %d moves.\n"
           "The minimal number of moves required to solve the Towers of Hanoi is %.lf.\n",
           moveCount, pow(2, DISKS) - 1);

    getchar(); // remove \n from previous input from stdin
    waitForEnter();

    // return console to original state
    restoreConsole();
    clearScreenToBottom();

    return 0;
}
