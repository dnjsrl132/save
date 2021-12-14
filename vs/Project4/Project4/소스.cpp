#include<stdio.h>
#include<stdlib.h>
#include "Çì´õ.h"
int main() {
	int *newData;
	int *nodeData;
	NODE* node;
	newData = (int*)malloc(sizeof(int));
	*newData = 7;
	node = createNode(newData);
	nodeData = (int*)node->data;
	printf("%d", *nodeData);
	return 0;
}