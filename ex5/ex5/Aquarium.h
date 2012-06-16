#pragma once
#ifndef AQUARIUM
#define AQUARIUM

class Aquarium
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