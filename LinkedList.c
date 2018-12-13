#pragma once
#include "linkedList.h"

#define CACHE_MAX 10

char* getDestination(LinkedList *List, int id)
{

	if (List->head == nullptr)
		return nullptr;
	Node* nodeHolder = List->head;

	if (nodeHolder->id == id)
		return nodeHolder->txt;
	
	while (nodeHolder->next != nullptr)
	{
		if (nodeHolder->next->id == id)
		{
			newLRU(List, nodeHolder->next, nodeHolder);
			return List->head->txt;
		}
		nodeHolder = nodeHolder->next;
	}

	return nullptr;
}

Node* createNode(int id, char* txt)
{
	Node* newNode = malloc(sizeof(Node));
	newNode->txt = malloc(sizeof(char)*strlen(txt) + 1);
	strcpy(newNode->txt, txt);
	newNode->id = id;
	newNode->next = nullptr;

}