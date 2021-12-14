#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include<stdlib.h> 
#include<stdbool.h> 
#include"listsADT.h"

void fillList(LIST*); 
void printList(LIST*);
void removeList(LIST*);
int compareInt(void* num1, void* num2);
int main() {
	LIST* list;
	list = createList(compareInt);
	fillList(list);
	removeList(list);
	printList(list);
	return 0;
} 
void fillList(LIST* list) {
	int category; 
	int item; 
	int* dataPtr;
	int* dataOutPtr;
	printf("Categorizing data:\n");
	srand(75);
	for (int i = 1; i <= 30; i++) {
		if (!(dataPtr = (int*)malloc(sizeof(int))))
			printf("OverFlow in fill Queues\a\n"), exit(100);
		*dataPtr = item = rand() % 50 + 1;
		if (searchList(list, dataPtr, (void**)&dataOutPtr)) {
			i--;
			continue;
		}
		addNode(list, dataPtr);
	}
	printList(list);
	printf("\nEnd of data categorization\n\n");
	return;
}
void printList(LIST* list) {
	int lineCount;
	int* dataPtr;
	int* dataOutPtr;
	LIST* temp;
	temp = createList(compareInt);
	lineCount = 0;
	while (!emptyList(list)) { 
		dataOutPtr = (int*)list->head->dataPtr;
		removeNode(list, dataOutPtr,(void**)&dataPtr); 
		addNode(temp, dataPtr);
		if (lineCount++ >= 10) { 
			lineCount = 1; 
			printf("\n"); 
		} 
		printf("%3d", *dataPtr); 
	}
	printf("\n");

	while (!emptyList(temp)) {
		dataOutPtr = (int*)temp->head->dataPtr;
		removeNode(temp, dataOutPtr, (void**)&dataPtr);
		addNode(list, dataPtr);
	}
	return;
}
void removeList(LIST* list) {
	int num;
	int* dataPtr;
	printf("Enter a number:");
	scanf("%d", &num);
	for (int i = num; i <= 50; i += num) {
		removeNode(list, &i, (void**)&dataPtr);
	}
}
int compareInt(void* num1, void* num2) {
	int key1; 
	int key2; 
	key1 = *(int*)num1; 
	key2 = *(int*)num2; 
	if (key1 < key2) 
		return -1; 
	if (key1 == key2) 
		return 0;
	return +1;
}
