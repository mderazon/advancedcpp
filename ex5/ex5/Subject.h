#pragma once
#ifndef SUBJECT
#define SUBJECT
#include "Observer.h"

class Subject
{
public:
	virtual ~Subject();
	virtual void Attach(Observer*);
	virtual void Detach(Observer*);
	virtual void Notify();
protected:
	Subject();
private:
	std::vector<Observer*> m_observers;
};
#endif