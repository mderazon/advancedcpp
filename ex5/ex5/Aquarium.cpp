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
	Notify("feed"); // notify the fishes they have food
}

void Aquarium::empty()
{
	fishim.clear(); // also calls the destructor of fish --> detach the observer
}

void Aquarium::pause()
{
	Notify("pause");
}

void Aquarium::play()
{
	Notify("play");
}

void Aquarium::add(std::string type)
{
	fishim.push_back(new Fish(type, this));
}

void Aquarium::remove(std::string type)
{
	// this removes all fishes of type "type"
	std::vector<Fish*>::iterator new_location = std::remove_if(fishim.begin(), fishim.end(),  [type](Fish* f) { return f->getType() == type; });
	fishim.erase(new_location, fishim.end());
}

std::string Aquarium::debug()
{
	std::ostringstream s;
	std::for_each(fishim.begin(), fishim.end(),  [&](Fish* f) {  s << f->getState(); });
	return s.str();
}

Aquarium::Aquarium()
{

}
