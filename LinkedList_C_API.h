typedef int DATA_TYPE;
typedef struct LinkedListNode LL_NODE;

enum STATUS {
    FAILURE = 0,
    SUCCESS = 1
};

struct LinkedListNode {

    DATA_TYPE value;
    LL_NODE* nextNode;

};

typedef struct LinkedListHead {

    int numberOfElements;
    LL_NODE* nextNode;

} LL_HEAD;


//Functions for creating
int createLinkedList(LL_HEAD** head_ptr_ptr);
int createLinkedListNode(DATA_TYPE val, LL_NODE** node_ptr_ptr);
int insertNewElementToLinkedList(LL_HEAD* head_ptr, DATA_TYPE val);
int getNumElementsInLinkedList(LL_HEAD* head_ptr);

//Functions to delete and remove
int removeElementWithVal(LL_HEAD* head_ptr, DATA_TYPE val);
int removeElementAtIndex(LL_HEAD* head_ptr, int index);
int deleteLinkedList(LL_HEAD* head_ptr);

//Functions to print
int printElementsOfLinkedList(LL_HEAD* head_ptr);
void reverseOrderRecursion(LL_NODE* node_ptr);
int printLinkedListInReverse(LL_HEAD* head_ptr);

//Functions to get values from linked list
int linkedListAsArray(LL_HEAD* head_ptr, DATA_TYPE ary[]);
int getElementAtIndex(LL_HEAD* head_ptr, int index, DATA_TYPE* returnValue);
int isInLinkedList(LL_HEAD* head_ptr, DATA_TYPE searchValue);
int getElementIndex(LL_HEAD* head_ptr, DATA_TYPE searchValue);