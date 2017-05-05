#include <iostream>
#include "LinkedList.h"

void AddNode(LinkedList * leftElement) {
	if (leftElement) {
		leftElement->link = (node)calloc(1, sizeof(LinkedList));
		leftElement->link->data = NULL;
	}
	else {
		leftElement = (node)calloc(1, sizeof(LinkedList));
		leftElement->data = NULL;
	}
}

LinkedList * CreateList(uint32_t elementCount) {
	if (!elementCount) return NULL;
	node list = NULL, firstElement = NULL;
	list = firstElement = (node)calloc(1, sizeof(LinkedList));
	firstElement->data = calloc(1, sizeof(LinkedList));
	while (--elementCount > 0) { AddNode(list); list = list->link; }
	return firstElement;
}

void SetNode(LinkedList * list, uint32_t elementCount, void * data) {
	while (elementCount-- > 0) list = list->link;
	list->data = data;
}

void PrintNode(node element, TYPE t) {//Not able to print struct, only support CHAR, INT, FLOAT, DOUBLE
	switch (t) {
	case CHAR:
		printf("%c", *(char *)(element->data));
		break;
	case INT:
		printf("%d", *(int *)(element->data));
		break;
	case FLOAT:
		printf("%f", *(float *)(element->data));
		break;
	case DOUBLE:
		printf("%lf", *(double *)(element->data));
		break;
	}
}

void PrintList(LinkedList * list, TYPE t) {//Not able to print struct, only support CHAR, INT, FLOAT, DOUBLE
	node ptr = list;
	switch (t) {
	case CHAR:
		while (ptr) { printf("%c", *(char *)(ptr->data)); ptr = ptr->link; }
		break;
	case INT:
		while (ptr) { printf("%d", *(int *)(ptr->data)); ptr = ptr->link; }
		break;
	case FLOAT:
		while (ptr) { printf("%f", *(float *)(ptr->data)); ptr = ptr->link; }
		break;
	case DOUBLE:
		while (ptr) { printf("%lf", *(double *)(ptr->data)); ptr = ptr->link; }
		break;
	}
}

LinkedList * ListEle(LinkedList * list, uint32_t elementCount) {
	while (elementCount-- > 0) list = list->link;
	return list;
}

void * StructNode(node element) {
	return element->data;
}

void DeleteNode(LinkedList * leftElement) {
	if (!(leftElement) || !(leftElement->link)) return;
	void * tmp = leftElement->link;
	if (tmp) leftElement->link = leftElement->link->link;
	free(tmp);
}