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


int createLinkedList(LL_HEAD** head_ptr_ptr);
int createLinkedListNode(DATA_TYPE val, LL_NODE** node_ptr_ptr);
int insertNewElementToLinkedList(LL_HEAD* head_ptr, DATA_TYPE val);
int printElementsOfLinkedList(LL_HEAD* head_ptr);
int getNumElementsInLinkedList(LL_HEAD* head_ptr);
int removeElementWithVal(LL_HEAD* head_ptr, DATA_TYPE val);
int removeElementAtIndex(LL_HEAD* head_ptr, int index);
int deleteLinkedList(LL_HEAD* head_ptr);