#include "linkedlist.h"
#ifndef LOGIC_H
#define LOGIC_H

void calculatorControl(char ** arr, char * fileName);
void moveCursor(char ** arr, char flag);
void moveUp(char ** arr);
void moveDown(char ** arr);
void moveLeft(char ** arr);
void moveRight(char ** arr);
void selectKey(char ** arr, int * total, int * val, LinkedList * list, char * fileName);
void saveCalculation(int total, LinkedList * list, char * fileName);
int concat(int x, int y);
int getCurrentCursorPositionX(char ** arr);
int getCurrentCursorPositionY(char ** arr);

#endif