#define _CRT_SECURE_NO_WARNINGS
#include "LRUcache.h"


LRUCache::LRUCache()
{
	linkedList = new LinkedList();
	linkedList->head = NULL;

}


void LRUCache::AddtoCache(int id, std::string txt)
{
	char* destination = new char[txt.length() + 1];
	strcpy(destination, txt.c_str());
	AddNewNode(this->linkedList, id, destination);

}

std::string LRUCache::GetfromCache(int id) 
{
	char* cachetxt;

	cachetxt = getDestination(this->linkedList, id);
	if (cachetxt == NULL)
		return "";
	std::string cachestring(cachetxt);
	return cachestring;

}

