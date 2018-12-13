#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "DisplayMessageEndpoint.h"
#include <Windows.h>
#include "LRUcache.h"
extern "C" {
#include "LinkedList.h"
}

std::string GetDestinationFrom(int destinationId, LRUCache *LRUCache)
{

	DisplayMessageDestinationService service;
	std::string destination(LRUCache->GetfromCache(destinationId));
	if (destination.empty())
	{
		destination = service.GetDestinationName(destinationId);
		LRUCache->AddtoCache(destinationId, destination);
	}
	return destination;

}

int main()
{
	//LRUCache cacheForDestinations(10);
	
	SetConsoleOutputCP(1252);
	LRUCache* Cache = new LRUCache();

	DisplayMessageEndpoint *endPoint = new DisplayMessageEndpoint();
	while (true)
	{
		DisplayMessageEndpoint::DisplayEntry nextDisplayMessage = endPoint->GetDisplayMessage();
		std::cout << nextDisplayMessage.time << "   " << nextDisplayMessage.newTime 
			<< "      " << nextDisplayMessage.track << "  " << GetDestinationFrom(nextDisplayMessage.destinationId, Cache)
			<< std::endl;
	}
}