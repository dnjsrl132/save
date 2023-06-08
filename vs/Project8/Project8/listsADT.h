#pragma once
typedef struct node {
	void* dataPtr;
	struct node* link;
}NODE;
typedef struct {
	int count;
	NODE* pos;
	NODE* head;
	NODE* rear;
	int(*compare)(void* argu1, void* argu2);
}LIST;

LIST* createList(int (*compare)(void* argu1, void* argu2));
LIST* destroyList(LIST* list);
int addNode(LIST* pList, void* dataInPtr);
bool removeNode(LIST* pList, void* keyPtr, void** dataOutPtr);
bool searchList(LIST* pList, void* pArgu, void** pDataOut);
bool retrieveNode(LIST* pList, void* pArgu, void** dataOutPtr);
bool travers(LIST* pList, int fromWhere, void** dataOutPtr);
int listCount(LIST* pList);
bool emptyList(LIST* pList);
bool fullList(LIST* pList);
static int _insert(LIST* pList, NODE* pPre, void* dataInPtr);
static void _delete(LIST* pList, NODE* pPre, NODE* pLoc, void** dataOutPtr);
static bool _search(LIST* pList, NODE** pPre, NODE** pLoc, void* pArgu);

LIST* createList(int (*compare)(void* argu1, void* argu2)) {
	LIST* list;

	list = (LIST*)malloc(sizeof(LIST));
	if (list) {
		list->head = NULL;
		list->pos = NULL;
		list->rear = NULL;
		list->count = 0;
		list->compare = compare;
	}
	return list;
}
LIST* destroyList(LIST* list) {
	NODE* deletePtr;
	if (list) {
		while (list->count > 0) {
			free(list->head->dataPtr);
			deletePtr = list->head;
			list->head = list->head->link;
			(list->count)--;
			free(deletePtr);
		}
		free(list);
	}
	return NULL;
}
int addNode(LIST* pList, void* dataInPtr) {
	bool found;
	bool success;
	NODE* pPre;
	NODE* pLoc;
	found = _search(pList, &pPre, &pLoc, dataInPtr);
	if (found)
		return (+1);
	success = _insert(pList, pPre, dataInPtr);
	if (!success)
		return (-1);
	return(0);
}
bool removeNode(LIST* pList, void* keyPtr, void** dataOutPtr) {
	bool found;
	NODE* pPre;
	NODE* pLoc;

	found = _search(pList, &pPre, &pLoc, keyPtr);
	if (found)
		_delete(pList, pPre, pLoc, dataOutPtr);
	return found;
}
bool searchList(LIST* pList, void* pArgu, void** pDataOut) {
	bool found;
	NODE* pPre;
	NODE* pLoc;

	found = _search(pList, &pPre, &pLoc, pArgu);
	if (found)
		*pDataOut = pLoc->dataPtr;
	else
		*pDataOut = NULL;
	return found;
}
bool retrieveNode(LIST* pList, void* pArgu, void** dataOutPtr) {
	bool found;
	NODE* pPre;
	NODE* pLoc;
	found = _search(pList, &pPre, &pLoc, pArgu);
	if (found) {
		*dataOutPtr = pLoc->dataPtr;
		return true;
	}
	*dataOutPtr = NULL;
	return false;
}
bool travers(LIST* pList, int fromWhere, void** dataOutPtr) {
	if (pList->count == 0)
		return false;
	if (fromWhere == 0) {
		pList->pos = pList->head;
		*dataOutPtr = pList->pos->dataPtr;
		return true;
	}
	else {
		pList->pos = pList->pos->link;
		*dataOutPtr = pList->pos->dataPtr;
		return true;
	}
}
int listCount(LIST* pList) { return pList->count; }
bool emptyList(LIST* pList) { return (pList->count == 0); }
bool fullList(LIST* pList) {
	NODE* temp;
	if ((temp = (NODE*)malloc(sizeof(*pList->head)))) {
		free(temp);
		return false;
	}
	return true;
}

static int _insert(LIST* pList, NODE* pPre, void* dataInPtr) {
	NODE* pNew;
	if (!(pNew = (NODE*)malloc(sizeof(NODE))))
		return false;
	pNew->dataPtr = dataInPtr;
	pNew->link = NULL;

	if (pPre == NULL) {
		pNew->link = pList->head;
		pList->head = pNew;
		if (pList->count == 0)
			pList->rear = pNew;
	}
	else {
		pNew->link = pPre->link;
		pPre->link = pNew;
		if (pNew->link == NULL)
			pList->rear = pNew;
	}
	(pList->count)++;
	return true;
}
static void _delete(LIST* pList, NODE* pPre, NODE* pLoc, void** dataOutPtr) {
	*dataOutPtr = pLoc->dataPtr;
	if (pPre == NULL)
		pList->head = pLoc->link;
	else
		pPre->link = pLoc->link;

	if (pLoc->link == NULL)
		pList->rear = pPre;
	(pList->count)--;
	free(pLoc);
	return;
}
static bool _search(LIST* pList, NODE** pPre, NODE** pLoc, void* pArgu) {
#define COMPARE \
	((*pList->compare)(pArgu,(*pLoc)->dataPtr))
#define COMPARE_LAST\
	((*pList->compare)(pArgu,pList->rear->dataPtr))

	int result;

	*pPre = NULL;
	*pLoc = pList->head;
	if (pList->count == 0)
		return false;

	if (COMPARE_LAST > 0) {
		*pPre = pList->rear;
		*pLoc = NULL;
		return false;
	}
	while ((result = COMPARE) > 0) {
		*pPre = *pLoc;
		*pLoc = (*pLoc)->link;
	}
	if (result)
		return false;
	else
		return true;
}