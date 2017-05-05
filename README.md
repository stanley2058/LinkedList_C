# LinkedList_C
LinkedList for C

Define new LinkedList like: LinkedList * list;

Functions:

//Create a new LinkedList

LinkedList * CreateList(uint32_t elementCount);


//Will add a node after 'leftElement'

void AddNode(LinkedList * leftElement);


//Ex: SetNode(list, ELEMENT_COUNTS, dataPtr);

void SetNode(LinkedList * list, uint32_t elementCount, void * data);


//Not able to print struct, only support CHAR, INT, FLOAT, DOUBLE

void PrintNode(node element, TYPE t);


//Not able to print struct, only support CHAR, INT, FLOAT, DOUBLE

void PrintList(LinkedList * list, TYPE t);


//Ex: ListEle(list, 0); Will get the first node in list

LinkedList * ListEle(LinkedList * list, uint32_t elementCount);


//Ex: (type *)StructNode(node);

void * StructNode(node element);


//Will remove the node which is the next of 'leftElement'

void DeleteNode(LinkedList * leftElement);

