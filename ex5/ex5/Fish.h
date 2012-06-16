#pragma once
#ifndef FISH
#define FISH
class FishImpl; // forward declaration

class Fish
{
public:
	Fish(std::string type);
	~Fish(void);

	std::string feed();
	std::string getState();
	std::string getType();

protected:
	FishImpl* m_Fish; // ptr to implementation
};
#endif