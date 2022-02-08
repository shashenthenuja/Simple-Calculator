/* *********************************************************************
* File:       linkedlist.c
* Author:     G.G.T.Shashen
* Created:    06/09/2021
* Modified:   06/11/2021
* Desc:       Linked list implementation from Assignment 2
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

/* creating and initializing the linked list */
LinkedList * createLinkedList()
{
    LinkedList * ll;
    ll = (LinkedList *) malloc(sizeof(LinkedList));
    ll->head = NULL;
    return ll;
}

/**
 * @brief  Inserting data to the linked list
 * @note   Inserting data to the beginning of the given linked list with given data
 * @param  list: Linked list
 * @param  pdata: data to be inserted to the linked list
 * @retval void: none
 */
void insertFirst(LinkedList * list, void * pdata)
{
    struct LinkedListNode* newNode;
    newNode = malloc(sizeof(struct LinkedListNode));
    newNode->data = pdata;
    newNode->next = list->head;
    list->head = newNode;
}

/**
 * @brief  Remove data in the linked list
 * @note   Remove data at the beginning of the linked list
 * @param  list: Linked list
 * @retval void*: return empty status
 */
void* removeFirst(LinkedList * list)
{
    struct LinkedListNode * temp;
    void* empty;
    empty = NULL;
    if (list->head == NULL)
    {
        empty = NULL;
    }else {
        temp = list->head;
        list->head = temp->next;
        free(temp);
    }
    return empty;
}

/**
 * @brief  Free data in the linked list
 * @note   Free the all the nodes and the data in the linked list
 * @param  list: Linked list
 * @retval void: none
 */
void freeLinkedList(LinkedList * list)
{
    struct LinkedListNode * current, * nextNode;
    current = list->head;
    while (current != NULL)
    {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    free(list);
}

/**
 * @brief  Check if the linked list is empty
 * @note   Check if the linked list is empty
 * @param  list: Linked list
 * @retval int: empty status
 */
int isEmpty(LinkedList *list){
    int empty;
    if (list == NULL)
    {
        empty = TRUE;
    }else
    {
        empty = FALSE;
    }
    return empty;
}