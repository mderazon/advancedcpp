#include "stdafx.h"
#include "Fish.h"
#include "FishFactory.h"

Fish::Fish(std::string type, Subject* s)
{
	m_Fish = FishFactory::CreateFish(type);
	Observer::sbj = s;
	Observer::sbj->Attach(this);
}

Fish::~Fish(void)
{
	Observer::sbj->Detach(this);
	delete m_Fish;
	m_Fish = 0;
}

std::string Fish::feed()
{
	return m_Fish->feed();
}

std::string Fish::getState()
{
	return m_Fish->getState();
}

std::string Fish::getType()
{
	return m_Fish->getType();
}

void Fish::Update( Subject* ChngSubject )
{
}