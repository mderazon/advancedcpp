#include "stdafx.h"
#include "FishFactory.h"

FishFactory::FishFactory(void)
{
}

FishFactory::~FishFactory(void)
{
}

FishImpl* FishFactory::CreateFish( const std::string& impl )
{
	FishImpl* ptrFish = 0;
	if (impl == "Gold")
		ptrFish = new GoldFishImpl();
	if (impl == "Piranha")
		ptrFish = new PiranhaFishImpl();
	if (impl == "Salmon")
		ptrFish = new SalmonFishImpl();
	return ptrFish;
}