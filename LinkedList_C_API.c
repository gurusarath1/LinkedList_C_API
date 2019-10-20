#include <stdio.h>
#include <stdlib.h>
#include "LinkedList_C_API.h"

int createLinkedList(LL_HEAD** head_ptr_ptr)
{
    LL_HEAD* head = (LL_HEAD*) malloc(sizeof(LL_HEAD));

    if(head == NULL)
    {
        return FAILURE;

    } else {
        head->nextNode = NULL;
        *head_ptr_ptr = head;
        return SUCCESS;

    }
}


int createLinkedListNode(DATA_TYPE val, LL_NODE** node_ptr_ptr)
{
    LL_NODE* node = (LL_NODE*) malloc(sizeof(LL_NODE));

    if (node == NULL)
    {

        return FAILURE;
    } else {
        node->value = val;
        node->nextNode = NULL;
        *node_ptr_ptr = node;
        return SUCCESS;

    }
}

int insertNewElementToLinkedList(LL_HEAD* head_ptr, DATA_TYPE val)
{
    LL_NODE* new_node_ptr;
    LL_NODE* next;


    if(head_ptr == NULL)
    {
        return FAILURE;
    } else
    {
        head_ptr->numberOfElements = head_ptr->numberOfElements + 1;
    }


    if( createLinkedListNode(val, &new_node_ptr) )
    {
        next = head_ptr->nextNode;

        if(next == NULL)
        {
            head_ptr->nextNode = new_node_ptr;
            return SUCCESS;
        }


        while(next != NULL)
        {

            if(next->nextNode == NULL)
            {
                next->nextNode = new_node_ptr;
                break;
            }

            next = next->nextNode;
        }

        return SUCCESS;
    }

    return FAILURE;
}

int printElementsOfLinkedList(LL_HEAD* head_ptr)
{
    LL_NODE* next_node = head_ptr->nextNode;
    while(next_node != NULL)
    {
        printf("%d  ", next_node->value);
        next_node = next_node->nextNode;
    }
    return SUCCESS;
}

int getNumElementsInLinkedList(LL_HEAD* head_ptr)
{
    return head_ptr->numberOfElements;
}

int removeElementWithVal(LL_HEAD* head_ptr, DATA_TYPE val)
{

    LL_NODE* next, *prev,*current;

    next = head_ptr->nextNode;
    prev = NULL;

    while(next != NULL)
    {
        current = next;
        next = current->nextNode;

        if(current->value == val)
        {
            free(current);

            if(prev == NULL)
            {
                // Removing the first element
                head_ptr->nextNode = next;
                head_ptr->numberOfElements = head_ptr->numberOfElements - 1;
                return SUCCESS;

            } else {

                //Removing element at a location that is not the first location
                prev->nextNode = next;
                head_ptr->numberOfElements = head_ptr->numberOfElements - 1;
                return SUCCESS;

            }

        }

        prev = current;

    }

    return FAILURE;

}

int removeElementAtIndex(LL_HEAD* head_ptr, int index)
{

    LL_NODE* next, *prev,*current;
    next = head_ptr->nextNode;
    prev = NULL;
    int i = 0;

    if(index < 0) return FAILURE;
    if(index >= getNumElementsInLinkedList(head_ptr)) return FAILURE;

    while(next != NULL)
    {
        current = next;
        next = current->nextNode;

        if(i == index)
        {
            free(current);

            if(prev == NULL)
            {
                // Removing the first element
                head_ptr->nextNode = next;
                head_ptr->numberOfElements = head_ptr->numberOfElements - 1;
                return SUCCESS;

            } else {

                //Removing element at a location that is not the first location
                prev->nextNode = next;
                head_ptr->numberOfElements = head_ptr->numberOfElements - 1;
                return SUCCESS;

            }

        }

        prev = current;
        i++;

    }

    return FAILURE;
}

int deleteLinkedList(LL_HEAD* head_ptr)
{
    LL_NODE* next = head_ptr->nextNode;
    LL_NODE* next2;

    if(head_ptr != NULL)
    {
        free(head_ptr);

        while(next != NULL)
        {
            next2 = next->nextNode;
            free(next);
            next = next2;
        }

    }

    return SUCCESS;

}
