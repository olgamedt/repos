#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
	int id;
	char *txt;
	struct Node *next;
}Node;

typedef struct LinkedList
{
	Node *head;

}LinkedList;

char* getDestination(LinkedList *List, int id);
Node* createNode(int id, char* txt);
void AddNewNode(LinkedList *List, int id, char *txt);
void RemoveLastNode(LinkedList *List);
void newLRU(LinkedList *List, Node *RecentlyUsed, Node *BeforeRecenlyUsed);
