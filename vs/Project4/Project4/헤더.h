#pragma once
typedef struct node {
	void* data;
	struct node* link;
}NODE;

NODE* createNode(void* data) {
	NODE* nodePtr;
	nodePtr = (NODE*)malloc(sizeof(NODE));
	nodePtr->data = data;
	nodePtr->link = NULL;
	return nodePtr;
}