#pragma once
#include <string>
extern "C" {
#include "LinkedList.h"
}


class LRUCache
{
public:
	
	LRUCache();
	void AddtoCache(int id, std::string txt);
	std::string GetfromCache(int id);
	
private:
	LinkedList * linkedList;
};