#include "stdafx.h"
#include "participant.h"


participant::participant(int id, std::string name) : id(id), name(name) {}

participant::~participant() {}

int participant::getId() const
{
	return this->id;
}

std::string participant::getName() const
{
	return this->name;
}