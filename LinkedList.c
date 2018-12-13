#pragma once
#include "LinkedList.h"
#define CACHE_MAX 10
#define _CRT_SECURE_NO_WARNINGS

char* getDestination(LinkedList *List, int id)
{

	if (List->head == NULL)
		return NULL;
	Node* nodeHolder = List->head;

	if (nodeHolder->id == id)
		return nodeHolder->txt;

	while (nodeHolder->next != NULL)
	{
		if (nodeHolder->next->id == id)
		{
			newLRU(List, nodeHolder->next, nodeHolder);
			return List->head->txt;
		}
		nodeHolder = nodeHolder->next;
	}

	return NULL;
}

Node* createNode(int id, char* txt)
{
	Node* newNode = malloc(sizeof(Node));
	newNode->txt = malloc(sizeof(char)*strlen(txt) + 1);
	strcpy(newNode->txt, txt);
	newNode->id = id;
	newNode->next = NULL;
	return newNode;
}

void AddNewNode(LinkedList *List, int id, char *txt)
{
	Node* newNode = createNode(id, txt);
	if (List->head != NULL)
	{
		Node* nodeHolder = List->head;
		int ListLength = 0;

		while (ListLength != CACHE_MAX - 1)
		{

			if (ListLength == CACHE_MAX - 1)
				RemoveLastNode(List);
		}
		newNode->next = List->head;
	}
	List->head = newNode;
}

void RemoveLastNode(LinkedList *List)
{
	Node* nodeHolder = NULL;
	Node* newTail = NULL;
	nodeHolder = List->head;
	while(nodeHolder->next != NULL)
	{
		newTail = nodeHolder;
		nodeHolder = nodeHolder->next;
	}
	free(nodeHolder->txt);
	nodeHolder->txt = NULL;
	free(nodeHolder);
	nodeHolder = NULL;

	newTail->next = NULL;
}

void newLRU(LinkedList *List, Node *RecentlyUsed, Node *BeforeRecenlyUsed)
{
	if (RecentlyUsed->next == NULL)
		BeforeRecenlyUsed->next = NULL;
	else
		BeforeRecenlyUsed->next = RecentlyUsed->next;
	RecentlyUsed->next = List->head;
	List->head = RecentlyUsed;
}

