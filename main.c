/**********************************************************************
* File:       main.c
* Author:     G.G.T.Shashen
* Created:    01/11/2021
* Modified:   06/11/2021
* Desc:       Simple Calculator Program Final Assignment COMP1000
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "logic.h"
#include "linkedlist.h"

/**
 * @brief  Main function of the program
 * @note   calls the functions of the calculator
 * @param  argc: number of command line arguments
 * @param  argv: char array containing the command line arguments entered
 * @retval int: success status
 */
int main(int argc, char * argv[])
{
    int i;
    char **data;
    /* checking arguments */
    if (argc < 2)
    {
        printf("Usage : ./calculator <filename>\n");
    }else if (argc > 2)
    {
        printf("Usage : ./calculator <filename>\n");
    }else
    {
        /* creating malloc data for 2d array */
        data = (char **) malloc(sizeof(int *) * (8));
        for ( i = 0; i < (8); i++)
        {
            data[i] = NULL;
            data[i] = (char *) malloc(sizeof(int *) * (5));
        }
        /* calling random interface function to display a random interface to the screen */
        randomInterface(data);
        /* calling calculatorControl function to use the calculator interface */
        calculatorControl(data,argv[1]);
        /* freeing malloc data */
        for ( i = 0; i < (8); i++)
        {
            free(data[i]);
            data[i] = NULL;
        }
        free(data);
        data = NULL;
    }
    return 0;
}