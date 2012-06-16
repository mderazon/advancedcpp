#pragma once
#ifndef OBSERVER
#define OBSERVER
#include "stdafx.h"
class Subject;

class Observer
{
public:
	virtual	~Observer();
	virtual void Update(Subject* ChngSubject) = 0;
protected:
	Observer();
	Subject* sbj;
};

#endif