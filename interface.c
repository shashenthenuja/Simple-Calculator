/**********************************************************************
* File:       interface.c
* Author:     G.G.T.Shashen
* Created:    02/11/2021
* Modified:   06/11/2021
* Desc:       Calculator Interface implementation of the program
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "interface.h"
#include "logic.h"

/**
 * @brief  Display the current entered number to the top of the screen
 * @note   Display the current entered number from the keypad to the top of the screen
 * @param  num: current entered number from the keypad
 * @retval void: none
 */
void numberDisplay(int num)
{
    printf("---------\n");
    printf("|%7d|\n",num);
    printf("---------\n");
}

/**
 * @brief  Creation of the number pad
 * @note   Creation of the number pad and storing to the 2D array
 * @param  arr: 2D char array
 * @retval void: none
 */
void numberPad(char ** arr)
{
    int r;
    int c;
    int i;
    i=1;
    /* insert white spaces in the array */
    for ( r = 0; r < 8; r++)
    {
        for ( c = 0; c < 5; c++)
        {
            arr[r][c] = ' ';   
        }
    }
    /* insert number pad numbers */
    for ( r = 0; r < 8; r++)
    {
        for ( c = 0; c < 5; c++)
        {
            if (r%2==0 && c%2==0)
            {
                arr[r][c] = i + '0';
                i++;
            }
        }
    }
    /* insert number pad operation symbols */
    arr[6][0] = '+';
    arr[6][2] = '0';
    arr[6][4] = '=';
    /* initializing cursor position in the array */
    initializeCursor(arr);
}

/**
 * @brief  Creation of the number pad with the rows changed
 * @note   Creation of the number pad with the rows changed and storing to the 2D array
 * @param  arr: 2D char array
 * @retval void: none
 */
void numberPadInverse(char ** arr)
{
    int r;
    int c;
    int i;
    i=1;
    /* insert white spaces in the array */
    for ( r = 0; r < 8; r++)
    {
        for ( c = 0; c < 5; c++)
        {
            arr[r][c] = ' ';   
        }
    }
    /* insert number pad numbers */
    for ( r = 7; r >= 0; r--)
    {
        for ( c = 0; c < 5; c++)
        {
            if (r%2==0 && c%2==0)
            {
                arr[r][c] = i + '0';
                i++;
            }
        }
    }
    /* insert number pad operation symbols */
    arr[0][0] = '+';
    arr[0][2] = '0';
    arr[0][4] = '=';
    /* initializing cursor position in the array */
    initializeCursor(arr);
}

/**
 * @brief  Storing the initial position of the cursor into the array
 * @note   Storing the initial position of the cursor into the array
 * @param  arr: 2D char array
 * @retval void: none
 */
void initializeCursor(char ** arr)
{
    arr[1][0] = '^';
}

/**
 * @brief  Choosing a random interface between the 2 interfaces
 * @note   Choosing a random interface with a 50% chance of getting an interface from the 2 options
 * @param  arr: 2D char array
 * @retval void: none
 */
void randomInterface(char ** arr)
{
    int value;
    srand((unsigned) time(0));
    /* generating a random value that has a 50% of chance of getting  between 1 and 0 */
    value = (rand() % 100) < 50;
    switch (value)
    {
    case 0:
        numberPad(arr);
        break;
    case 1:
        numberPadInverse(arr);
        break;
    default:
        break;
    }
}

/**
 * @brief  Printing the total value
 * @note   Printing the total value to the screen from the given int parameter
 * @param  val: Total value
 * @retval void: none
 */
void totalValue(int val)
{
    printf("\ncurrent total : %d\n",val);
}

/**
 * @brief  Printing the interface to the screen
 * @note   Printing the interface to the screen with the given parameters
 * @param  data: 2D array
 * @param  total: total value of the calculation
 * @param  val: current value entered from the keypad
 * @retval void: none
 */
void printInterface(char ** data, int total, int val)
{
    int r;
    int c;
    r = 0;
    c = 0;
    /* displaying the entered number to the screen */
    numberDisplay(val);
    printf("\n");
    /* printing the interface with values from the array */
    for ( r = 0; r < 8; r++)
    {
        for ( c = 0; c < 5; c++)
        {
            printf("%c", data[r][c]);
        }
        printf("\n");
    }
    /* printing the total value calculated to the screen */
    totalValue(total);
}