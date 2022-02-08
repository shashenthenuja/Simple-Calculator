/* *********************************************************************
* File:       fileIO.c
* Author:     G.G.T.Shashen
* Created:    05/11/2021
* Modified:   06/11/2021
* Desc:       FileIO implementation to save the calculated data to a file
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "fileIO.h"
#include "linkedlist.h"

/**
 * @brief  Save the total calculation to a file
 * @note   Create and save the total calculation to a file of choice
 * @param  total: Total of the calculation
 * @param  list: Linked List
 * @param  fileName: file name of the save file
 * @retval void: none
 */
void saveCalculation(int total, LinkedList * list, char * fileName)
{
    FILE * fp = fopen(fileName,"w");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
    }else
    {
        /* check if the linked list is empty */
        if (list->head == NULL)
        {
            fprintf(fp,"0");
        }else
        {
            /* check if the linked list has only one value and save without any operation symbols */
            if (*(int*)&list->head->data == total)
            {
                fprintf(fp,"%d",total);
            }else
            {
                /* while loop to get all the node data if the linked list is not empty */
                while (list->head != NULL)
                {
                    /* if the next node is empty save without + sign */
                    if (list->head->next == NULL)
                    {
                        fprintf(fp,"%d ",*(int *)&list->head->data);
                        removeFirst(list);
                    }else
                    /* save with + sign */
                    {
                        fprintf(fp,"%d + ",*(int *)&list->head->data);
                        removeFirst(list);
                    }
                }
                /* save the total value to the file */
                fprintf(fp,"= %d",total);
            }
        }
    }
    /* file pointer error handling */
    if (ferror(fp))
    {
        perror("Error writing to file!\n");
    }
    fclose(fp);
    fp = NULL;
}