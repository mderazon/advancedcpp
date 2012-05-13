#include "stdafx.h"


extendedAppointment::extendedAppointment( const std::string subject, float startHour, float endHour,list<int> p ) : appointment::appointment(const std::string subject, float startHour, float endHour)
{
	this->people = p;
}


const list<int>& extendedAppointment::getPeople() const
{
	return this->people;
}
