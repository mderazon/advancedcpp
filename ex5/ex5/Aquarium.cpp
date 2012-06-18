#include "stdafx.h"
#include "Aquarium.h"


Aquarium& Aquarium::getInstance()
{
	static Aquarium instance;	// Guaranteed to be destroyed.
	// Instantiated on first use.
	return instance;
}

void Aquarium::feed()
{
	Notify(); // notify the fishes they have food
}

void Aquarium::empty()
{
	fishim.clear(); // also calls the destructor of fish --> detach the observer
}

void Aquarium::pause()
{
}

void Aquarium::play()
{
}

void Aquarium::add(std::string type)
{
	fishim.push_back(new Fish(type, this));
}

void Aquarium::remove(std::string type)
{
	// this removes all fishes of type "type"
	std::vector<Fish*>::iterator it = std::remove_if(fishim.begin(), fishim.end(),  [type](Fish* f) { return f->getType() == type; });
}

std::string Aquarium::debug()
{
	return NULL;
}

Aquarium::Aquarium()
{

}
