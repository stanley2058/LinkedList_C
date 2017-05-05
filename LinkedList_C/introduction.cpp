#include <iostream>
#include "LinkedList.h"
#pragma warning (disable : 4996)

//How to: Define a LinkedList
void createALinkedListOfInteger() {
	/*Step1: Create a list of 5 integer element*/
	LinkedList * list_of_ints = CreateList(5);

	/*Step2: Fill in data*/
	const int MAX_ELEMENT = 5;
	int datas[MAX_ELEMENT] = {1, 8, 6, 10, 4};
	for (int i = 0; i < MAX_ELEMENT; i++) {
		SetNode(list_of_ints, i, datas + i);
	}

	/*Step3: Print out to see if it's correct*/
	//There are several ways to do this

	/*(1)*/
	node tmpNode = list_of_ints;
	for (int i = 0; i < MAX_ELEMENT; i++) {
		PrintNode(tmpNode, INT); //Not able to print struct, only support CHAR, INT, FLOAT, DOUBLE
		tmpNode = tmpNode->link;
		printf(" ");
	}printf("\n");

	/*(2) *RECOMMAND */
	for (int i = 0; i < MAX_ELEMENT; i++) {
		PrintNode(ListEle(list_of_ints, i), INT);
		printf(" ");
	}printf("\n");

	/*(3) *RECOMMAND ONLY FOR STRING */
	PrintList(list_of_ints, INT);
	printf("\n");

	/*(4)*/
	for (int i = 0; i < MAX_ELEMENT; i++) {
		printf("%d ", *(int *)(StructNode(ListEle(list_of_ints, i))) );
	}printf("\n");

}

//How to: Define a struct LinkedList

/*Step1: Define a data struct*/
struct people {
	int age;
	char name[20];
};

void createALinkedListOfStruct() {
	/*Step2: Create a LinkedList*/
	const unsigned int MAX_PEOPLE = 5;
	LinkedList * peopleList = CreateList(MAX_PEOPLE);

	/*Step3: Initialize & Input Data*/
	/*Or you can just let user keyin*/
	printf("Input %d People (Name/Age):\n", MAX_PEOPLE);
	people inputPtr[MAX_PEOPLE];
	for (int i = 0; i < MAX_PEOPLE; i++) {
		char buf[20];
		scanf("%[^\n]", buf); getchar();
		strcpy(inputPtr[i].name, strtok(buf, "/")); sscanf((strtok(NULL, "/")), "%d", &inputPtr[i].age);
		SetNode(peopleList, i, &(inputPtr[i]));
	}

	/*Step4: Print out to see if it's correct*/
	people * peoplePtr = NULL;
	for (int i = 0; i < MAX_PEOPLE; i++) {
		peoplePtr = (people *)StructNode(ListEle(peopleList, i));
		printf("Name: %s, Age: %d\n", peoplePtr->name, peoplePtr->age);
	}

}

int main() {
	createALinkedListOfInteger();

	createALinkedListOfStruct();
	return 0;
}