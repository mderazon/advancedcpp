#pragma once
#ifndef FISHFACTORY
#define FISHFACTORY

#include "FishImpl.h"

class FishFactory
{
public:
	static FishImpl* CreateFish(const std::string& impl);
private:
	FishFactory(void);
	~FishFactory(void);
};
#endif