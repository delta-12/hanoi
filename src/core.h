#ifndef __CORE_H__
#define __CORE_H__

// wait for ENTER keypress
// use getchar() to remove \n from previous input from stdin before calling
void waitForEnter();

// overwrite what is currently displayed on console w/o scrolling
void clearScreenInPlace();

#endif