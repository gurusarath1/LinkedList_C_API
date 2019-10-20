#include <stdio.h>
#include <stdlib.h>
#include "LinkedList_C_API.h"

int main(void)
{

    LL_HEAD* linkedList1;

    if(createLinkedList(&linkedList1))
    {
        insertNewElementToLinkedList(linkedList1, 5);
        insertNewElementToLinkedList(linkedList1, 55);
        insertNewElementToLinkedList(linkedList1, 2);
        insertNewElementToLinkedList(linkedList1, 9);
        insertNewElementToLinkedList(linkedList1, 52);
        insertNewElementToLinkedList(linkedList1, 123);

        printf("\n%d\n",getNumElementsInLinkedList(linkedList1));
        printElementsOfLinkedList(linkedList1);
        printf("\n");
        printLinkedListInReverse(linkedList1);

        removeElementAtIndex(linkedList1, 1); // 55 removed
        removeElementWithVal(linkedList1, 5);
        removeElementWithVal(linkedList1, 123);

        if(removeElementWithVal(linkedList1, 999) == FAILURE)
        {
            printf("\nElement Does not exist !!");
        }

        printf("\n%d\n",getNumElementsInLinkedList(linkedList1));
        printElementsOfLinkedList(linkedList1);

        printf("\n");
        deleteLinkedList(linkedList1);

    }

    printf("\n----------------------------------------------------------\n");

    LL_HEAD* linkedlist2;
    int arrayX[100], numElements;
    DATA_TYPE valX;

    createLinkedList(&linkedlist2);
    insertNewElementToLinkedList(linkedlist2, 10);
    insertNewElementToLinkedList(linkedlist2, 89);
    insertNewElementToLinkedList(linkedlist2, 256);
    insertNewElementToLinkedList(linkedlist2, 13);
    insertNewElementToLinkedList(linkedlist2, 200);
    insertNewElementToLinkedList(linkedlist2, 50);
    insertNewElementToLinkedList(linkedlist2, 91);
    insertNewElementToLinkedList(linkedlist2, 100);
    insertNewElementToLinkedList(linkedlist2, 124);
    insertNewElementToLinkedList(linkedlist2, 998);

    printElementsOfLinkedList(linkedlist2);
    numElements  = linkedListAsArray(linkedlist2, arrayX);

    printf("\nNumber of elements copied to array = %d\n", numElements);

    for(int i=0; i<numElements; i++)
    {
        printf("%d  ", arrayX[i]);
    }

    getElementAtIndex(linkedlist2, 3, &valX);
    printf("\nGet element at index %d = %d", 3, valX);

    getElementAtIndex(linkedlist2, 0, &valX);
    printf("\nGet element at index %d = %d", 0, valX);

    getElementAtIndex(linkedlist2, 6, &valX);
    printf("\nGet element at index %d = %d", 6, valX);


    printf("\nCheck if element %d is in linkedlist2 = %d", 3, isInLinkedList(linkedlist2, 3));
    printf("\nCheck if element %d is in linkedlist2 = %d", 998, isInLinkedList(linkedlist2, 998));
    printf("\nCheck if element %d is in linkedlist2 = %d", 10, isInLinkedList(linkedlist2, 10));
    printf("\nCheck if element %d is in linkedlist2 = %d", 91, isInLinkedList(linkedlist2, 91));
    printf("\nCheck if element %d is in linkedlist2 = %d", 101, isInLinkedList(linkedlist2, 101));

    printf("\nelement %d is at %d", 3, getElementIndex(linkedlist2, 3));
    printf("\nelement %d is at %d", 998, getElementIndex(linkedlist2, 998));
    printf("\nelement %d is at %d", 10, getElementIndex(linkedlist2, 10));
    printf("\nelement %d is at %d", 91, getElementIndex(linkedlist2, 91));
    printf("\nelement %d is at %d", 101, getElementIndex(linkedlist2, 101));

    return 0;
}
