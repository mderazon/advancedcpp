#include "stdafx.h"
#include "appointment.h"



apppointment::apppointment(const std::string subject, float startHour, float endHour)
{
	this->subject = subject;
	this->startHour = startHour;
	this->endHour = endHour;

}


void apppointment::setSubject(const std::string subject)
{
	this->subject = subject;
}

void apppointment::setStartHour(const float startHour)
{
	this->getStartHour =startHour;
}

void apppointment::setEndHour(const float endHour)
{
	this->endHour = endHour;
}



const std::string& apppointment::getSubject() const
{
	return subject;
}

const float apppointment::getStartHour() const
{
	return startHour;
}

const float apppointment::getEndHour() const
{
	return endHour;
}

bool apppointment::operator==( const apppointment& a )
{
	return (a.getStartHour() == startHour) && (a.getEndHour() == endHour) && (a.getSubject() == subject);
}

