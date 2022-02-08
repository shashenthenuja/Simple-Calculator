/**********************************************************************
* File:       logic.c
* Author:     G.G.T.Shashen
* Created:    02/11/2021
* Modified:   06/11/2021
* Desc:       Calculator logic implementation with all the functionalities
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include "logic.h"
#include "terminal.h"
#include "interface.h"
#include "linkedlist.h"
#include "fileIO.h"

/**
 * @brief  Control the calculator
 * @note   function to control all the operations in the calculator
 * @param  arr: 2D array
 * @param  fileName: file name of the save file
 * @retval void: none
 */
void calculatorControl(char ** arr, char * fileName)
{
    int cont;
    int total;
    int val;
    char input;
    char flag;
    /* creating the linked list */
    LinkedList * list = createLinkedList();
    cont = 1;
    val = 0;
    total = 0;
    system("clear");
    printInterface(arr,total,val);
    /* do while to loop the user input */
    do
    {
        /* taking input from the user */
        disableBuffer();
        scanf(" %c", &input);
        enableBuffer();
        /* switch function to get the valid control input from the user */
        switch (input)
        {
        /* calling appropriate functions to the valid cases */
        case 'w':
            flag = 'w';
            moveCursor(arr,flag);
            printInterface(arr,total,val);
            break;
        case 'a':
            flag = 'a';
            moveCursor(arr,flag);
            printInterface(arr,total,val);
            break;
        case 's':
            flag = 's';
            moveCursor(arr,flag);
            printInterface(arr,total,val);
            break;
        case 'd':
            flag = 'd';
            moveCursor(arr,flag);
            printInterface(arr,total,val);
            break;
        case 'e':
            system("clear");
            selectKey(arr,&total,&val,list,fileName);
            printInterface(arr,total,val);
            break;
        default:
            break;
        }
    } while (cont == 1);
    /* freeing linked list data */
    freeLinkedList(list);
}

/**
 * @brief  Move the cursor in the interface
 * @note   Move the cursor when the appropriate flag is passed
 * @param  arr: 2D array
 * @param  flag: stores the appropriate control key
 * @retval void: none
 */
void moveCursor(char ** arr, char flag)
{
    if (flag == 'w')
    {
        system("clear");
        moveUp(arr);
    }
    if (flag == 'a')
    {
        system("clear");
        moveLeft(arr);
    }
    if (flag == 's')
    {
        system("clear");
        moveDown(arr);
    }
    if (flag == 'd')
    {
        system("clear");
        moveRight(arr);
    }
}

/**
 * @brief  Move the cursor up
 * @note   Move the cursor up in the interface
 * @param  arr: 2D array
 * @retval void: none
 */
void moveUp(char ** arr)
{
    int cursorX;
    int cursorY;
    cursorX = getCurrentCursorPositionX(arr);
    cursorY = getCurrentCursorPositionY(arr);
    if (cursorX > 1 && arr[cursorX-2][cursorY]==' ')
    {
        arr[cursorX][cursorY] = ' ';
        arr[cursorX-2][cursorY] = '^';
    }else
    {
        arr[cursorX][cursorY] = '^';
    }
}

/**
 * @brief  Move the cursor down
 * @note   Move the cursor down in the interface
 * @param  arr: 2D array
 * @retval void: none
 */
void moveDown(char ** arr)
{
    int cursorX;
    int cursorY;
    cursorX = getCurrentCursorPositionX(arr);
    cursorY = getCurrentCursorPositionY(arr);
    if (cursorX < 7 && arr[cursorX+2][cursorY]==' ')
    {
        arr[cursorX][cursorY] = ' ';
        arr[cursorX+2][cursorY] = '^';
    }else
    {
        arr[cursorX][cursorY] = '^';
    }
}

/**
 * @brief  Move the cursor left
 * @note   Move the cursor left in the interface
 * @param  arr: 2D array
 * @retval void: none
 */
void moveLeft(char ** arr)
{
    int cursorX;
    int cursorY;
    cursorX = getCurrentCursorPositionX(arr);
    cursorY = getCurrentCursorPositionY(arr);
    if (cursorY > 0 && arr[cursorX][cursorY-2]==' ')
    {
        arr[cursorX][cursorY] = ' ';
        arr[cursorX][cursorY-2] = '^';
    }else
    {
        arr[cursorX][cursorY] = '^';
    }
}

/**
 * @brief  Move the cursor right
 * @note   Move the cursor right in the interface
 * @param  arr: 2D array
 * @retval void: none
 */
void moveRight(char ** arr)
{
    int cursorX;
    int cursorY;
    cursorX = getCurrentCursorPositionX(arr);
    cursorY = getCurrentCursorPositionY(arr);
    if (cursorY < 4 && arr[cursorX][cursorY+2]==' ')
    {
        arr[cursorX][cursorY] = ' ';
        arr[cursorX][cursorY+2] = '^';
    }else
    {
        arr[cursorX][cursorY] = '^';
    }
}

/**
 * @brief  Concatenate 2 int values
 * @note   Concatenate 2 passed values and return the int value
 * @param  a: First value to concatenate
 * @param  b: Second value to concatenate
 * @retval int: return the concatenated value
 */
int concat(int a, int b)
{
    a = (a * 10) + b;
    return a;
}

/**
 * @brief  Select the key by the current cursor position
 * @note   Selects the key infront of the cursor by the current cursor position
 * @param  arr: 2D array
 * @param  total: total value of the calculation
 * @param  val: current user entered value
 * @param  list: Linked list
 * @param  fileName: file name of the save file
 * @retval void: none
 */
void selectKey(char ** arr, int * total, int * val, LinkedList * list, char * fileName)
{
    int cursorX;
    int cursorY;
    int intVal;
    int temp;
    int i;
    int count;
    char key;
    char keyVal;
    char num[7];
    key = '0';
    intVal = 0;
    count = 0;
    cursorX = getCurrentCursorPositionX(arr);
    cursorY = getCurrentCursorPositionY(arr);
    temp = *val;
    for ( i = 0; i < 7; i++)
    {
        num[i] = 0;
    }
    /* loop to calculate the number of digits in the current values */
    do
    {
        temp /= 10;
        count++;
    } while (temp != 0);
    key = arr[cursorX-1][cursorY];
    if (key == '+')
    {
        /* adding the current value with the total value */
        intVal = *val;
        *total = *total + intVal;
        intVal = *total;
        /* checking and inserting to the linked list */
        if (*val != 0)
        {
            insertFirst(list,(void*)*val);
        }
        *val = 0;
    }else if (key == '=')
    {
        /* saving the calculated value to the text file */
        saveCalculation(*total,list,fileName);
        printInterface(arr,*total,*val);
        /* freeing malloc data and linked list */
        for ( i = 0; i < (8); i++)
        {
            free(arr[i]);
        }
        free(arr);
        freeLinkedList(list);
        exit(0);
    }else
    {
        /* displaying only 7 digits to the screen */
        if (count <= 6)
        {
            /* converting the correct values entered */
            if (*val == 0)
            {
                num[0] = key;
                keyVal = atoi(&num[0]);
                *val = keyVal;
            }else
            {
                num[0] = key;
                keyVal = atoi(&num[0]);
                intVal = concat(*val,keyVal);
                *val = intVal;
            }
        }
    }
}

/**
 * @brief  getting the current position of the cursor
 * @note   getting the current row coordinate of the cursor and returning
 * @param  arr: 2D array
 * @retval int: X coordinate of the cursor
 */
int getCurrentCursorPositionX(char ** arr)
{
    int i;
    int j;
    int cursorX;
    /* searching for the current row coordinate of the cursor position on the interface */
    for ( i = 0; i < 8; i++)
    {
        for ( j = 0; j < 5; j++)
        {
            if ((arr[i][j] == '^'))
            {
                cursorX = i;
            }
        }
    }
    return cursorX;
}

/**
 * @brief  getting the current position of the cursor
 * @note   getting the current column coordinate of the cursor and returning
 * @param  arr: 2D array
 * @retval int: Y coordinate of the cursor
 */
int getCurrentCursorPositionY(char ** arr)
{
    int i;
    int j;
    int cursorY;
    /* searching for the current column coordinate of the cursor position on the interface */
    for ( i = 0; i < 8; i++)
    {
        for ( j = 0; j < 5; j++)
        {
            if ((arr[i][j] == '^'))
            {
                cursorY = j;
            }
        }
    }
    return cursorY;
}