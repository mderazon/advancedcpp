#pragma once
#ifndef AQUARIUM
#define AQUARIUM
#include "Subject.h"
#include "Fish.h"

class Aquarium : public Subject
{
public:
	static Aquarium& getInstance();

	void feed();
	void empty();
	void pause();
	void play();
	void add(std::string type);
	void remove(std::string type);
	std::string debug();

private:
	Aquarium();
	Aquarium(Aquarium const&);
	void operator=(Aquarium const&);
	std::vector<Fish> fishim;
};
#endif