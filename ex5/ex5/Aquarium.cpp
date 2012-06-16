#include "stdafx.h"
#include "Aquarium.h"


Aquarium::Aquarium(void)
{
}

Aquarium& Aquarium::getInstance()
{
	static Aquarium instance;	// Guaranteed to be destroyed.
	// Instantiated on first use.
	return instance;
}

void Aquarium::feed()
{
}

void Aquarium::empty()
{
}

void Aquarium::pause()
{
}

void Aquarium::play()
{
}

void Aquarium::add()
{
}

void Aquarium::remove()
{
}

std::string Aquarium::debug()
{
	return NULL;
}