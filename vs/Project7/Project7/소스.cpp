#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include"queuesADT.h"

void fillQueues(QUEUE*, QUEUE*);
void printQueues(QUEUE*, QUEUE*);

void printOneQueue(QUEUE* pQueue);

int main() {
	QUEUE* Qodd;
	QUEUE* Qeven;

	Qodd = createQueue();
	Qeven = createQueue();

	fillQueues(Qodd,Qeven);
	printQueues(Qodd, Qeven);
	return 0;
}
void fillQueues(QUEUE* Qodd, QUEUE* Qeven) {
	int category;
	int item;
	int* dataPtr;

	printf("Categorizing data:\n");
	srand(time(NULL));
	for (int i = 1; i <= 50; i++) {
		if (!(dataPtr = (int*)malloc(sizeof(int))))
			printf("OverFlow in fill Queues\a\n"), exit(100);
		*dataPtr = item = rand() % 100+1;
		category = item % 2;
		printf("%3d", item);
		if (!(i % 10))
			printf("\n");
		switch (category) {
			case 0:enqueue(Qeven, dataPtr); break;
			case 1:enqueue(Qodd, dataPtr); break;
		}
	}
	printf("\nEnd of data categorization\n\n");
	return;
}
void printQueues(QUEUE* Qodd, QUEUE* Qeven) {
	printf("Data odd:\t");
	printOneQueue(Qodd);
	printf("Data even:\t");
	printOneQueue(Qeven);
	return;
}
void printOneQueue(QUEUE* pQueue) {
	int lineCount;
	int* dataPtr;
	lineCount = 0;
	while (!emptyQueue(pQueue)) {
		dequeue(pQueue, (void**)&dataPtr);
		if (lineCount++ >= 10) {
			lineCount = 1;
			printf("\n\t\t");
		}
		printf("%3d", *dataPtr);
	}
	printf("\n");
	return;
}