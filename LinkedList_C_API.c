#include <stdio.h>
#include <stdlib.h>
#include "LinkedList_C_API.h"

/*
Written By - Guru Sarath
Date - 19th Oct 2019
*/


/*


LL_HEAD                          LL_NODE                          LL_NODE
_____________________          _____________________          ______________________
|                   |         |                    |          |                    |
|                   |         |     value          |          |     value          |
|  numberOfElements |         |                    |          |                    |
|                   |         |                    |          |                    |
|           nextNode|-------->|            nextNode|--------->|            nextNode|--------->
---------------------         ----------------------          ----------------------

*/


/*
createLinkedList - This function creates the head node of linked list
*/
int createLinkedList(LL_HEAD** head_ptr_ptr)
{
    LL_HEAD* head = (LL_HEAD*) malloc(sizeof(LL_HEAD));

    if(head == NULL)
    {
        return FAILURE;

    } else {
        head->nextNode = NULL;
        *head_ptr_ptr = head; // Return the head pointer to the calling function
        return SUCCESS;

    }
}

/*
createLinkedListNode - This function creates a Linked list Node with value val
*/
int createLinkedListNode(DATA_TYPE val, LL_NODE** node_ptr_ptr)
{
    LL_NODE* node = (LL_NODE*) malloc(sizeof(LL_NODE));

    if (node == NULL)
    {

        return FAILURE;
    } else {
        node->value = val;
        node->nextNode = NULL;
        *node_ptr_ptr = node; // Return the node pointer to the calling function
        return SUCCESS;

    }
}

/*
insertNewElementToLinkedList - This function adds a new node with value = val to the end of the linked list
*/
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


    if( createLinkedListNode(val, &new_node_ptr) ) // Create a new node
    {
        next = head_ptr->nextNode;

        //If no element is present in the linked list
        if(next == NULL)
        {
            head_ptr->nextNode = new_node_ptr;
            return SUCCESS;
        }


        //If more than one element is present in the linked list
        //Traverse through the list till u reach the last element
        while(next != NULL)
        {

            if(next->nextNode == NULL) //Last node
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

/*
printElementsOfLinkedList - This function prints all the elements in a linked list
*/
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

/*
getNumElementsInLinkedList -  This functions returns the number of elements in the linked list
*/
int getNumElementsInLinkedList(LL_HEAD* head_ptr)
{
    return head_ptr->numberOfElements;
}

/*
removeElementWithVal - This function removes the node with value = val (only the first occurence)
*/
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

            if(prev == NULL) //If you are removing the first element from list
            {
                // Removing the first element
                head_ptr->nextNode = next;
                head_ptr->numberOfElements = head_ptr->numberOfElements - 1;
                return SUCCESS;

            } else { //If you are removing an element that is not the first element

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

/*
removeElementAtIndex - This function removes an element at index
*/
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

/*
deleteLinkedList - This function destroys the complete linked list
*/
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


/*
reverseOrderRecursion & printLinkedListInReverse - These two functions are used to print linkedlist in reverse order
*/
void reverseOrderRecursion(LL_NODE* node_ptr)
{
    if(node_ptr == NULL) return;

    reverseOrderRecursion(node_ptr->nextNode);
    printf("%d  ", node_ptr->value);

    return;

}
int printLinkedListInReverse(LL_HEAD* head_ptr)
{

    reverseOrderRecursion(head_ptr->nextNode);
    return SUCCESS;
}


/*
linkedListAsArray - Converts an linked list to array
*/
int linkedListAsArray(LL_HEAD* head_ptr, DATA_TYPE ary[])
{
    LL_NODE* next;
    int i;

    next = head_ptr->nextNode;
    i = 0;
    while(next != NULL)
    {

        ary[i] = next->value;
        next = next->nextNode;
        i++;

    }

    return i;
}


/*
getElementAtIndex - This function returns an element at an index through returnValue variable
*/
int getElementAtIndex(LL_HEAD* head_ptr, int index, DATA_TYPE* returnValue)
{

    LL_NODE* next;
    next = head_ptr->nextNode;
    int i = 0;

    if(index < 0) return FAILURE;
    if(index >= getNumElementsInLinkedList(head_ptr)) return FAILURE;

    while(next != NULL)
    {
        if(i == index)
        {
            *returnValue = next->value;
            return SUCCESS;
        }

        next = next->nextNode;
        i++;

    }

    return FAILURE;
}


/*
isInLinkedList - Used to check if an element is present in the linked list
*/
int isInLinkedList(LL_HEAD* head_ptr, DATA_TYPE searchValue)
{
    LL_NODE* next;
    next = head_ptr->nextNode;

    while(next != NULL)
    {
        if(next->value == searchValue)
        {
            return SUCCESS;
        }

        next = next->nextNode;

    }

    return FAILURE;

}

/*
getElementIndex - returns the location of an element; -1 if element is not present
*/
int getElementIndex(LL_HEAD* head_ptr, DATA_TYPE searchValue)
{
    LL_NODE* next;
    next = head_ptr->nextNode;
    int i = 0;

    while(next != NULL)
    {
        if(next->value == searchValue)
        {
            return i;
        }

        next = next->nextNode;
        i++;

    }

    return -1;

}