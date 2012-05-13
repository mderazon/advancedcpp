#include "stdafx.h"
#include "appointment.h"



appointment::appointment(const std::string subject, float startHour, float endHour)
{
	if (startHour < 0 || startHour >23 || endHour < 0 || endHour >23 || endHour >= startHour)
		throw incorrectAppointmentError;

	this->subject = subject;
	this->startHour = startHour;
	this->endHour = endHour;

}

appointment::~appointment() {
	this->subject.~string();
	this->startHour.~float();
	this->endHour.~float();
}

void appointment::setSubject(const std::string subject)
{
	this->subject = subject;
}

void appointment::setStartHour(const float startHour)
{
	this->getStartHour =startHour;
}

void appointment::setEndHour(const float endHour)
{
	this->endHour = endHour;
}



const std::string& appointment::getSubject() const
{
	return subject;
}

const float appointment::getStartHour() const
{
	return startHour;
}

const float appointment::getEndHour() const
{
	return endHour;
}

bool appointment::operator==( const appointment& a )
{
	return (a.getStartHour() == startHour) && (a.getEndHour() == endHour) && (a.getSubject() == subject);
}

