#include "stdafx.h"


extendedAppointment::extendedAppointment( const std::string subject, float startHour, float endHour,list<int> p ) : appointment(subject,startHour,endHour)
{
	this->people = p;
}

extendedAppointment::~extendedAppointment() {
	people.~list<int>();
}

const list<int>& extendedAppointment::getPeople() const
{
	return this->people;
}

EAppointmentType extendedAppointment::GetType() const
{
	return E_EXTENDED_APPOINTMENT;
}
