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

    return 0;
}
