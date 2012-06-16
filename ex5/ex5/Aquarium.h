#pragma once
#ifndef AQUARIUM
#define AQUARIUM
#include "Subject.h"

class Aquarium : public Subject
{
public:
	static Aquarium& getInstance();

	void feed();
	void empty();
	void pause();
	void play();
	void add();
	void remove();
	std::string debug();

private:
	Aquarium();

	Aquarium(Aquarium const&);
	void operator=(Aquarium const&);
};
#endif