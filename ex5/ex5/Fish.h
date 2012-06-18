#pragma once
#ifndef FISH
#define FISH
#include "FishImpl.h"
#include "Observer.h"
#include "Subject.h"

class Fish : public Observer
{
public:
	Fish(std::string type, Subject* s);
	~Fish(void);

	void feed();
	void play();
	void pause();
	std::string getState();
	std::string getType();
	void Update (Subject* ChngSubject, std::string message);

protected:
	FishImpl* m_Fish; // ptr to implementation
};
#endif