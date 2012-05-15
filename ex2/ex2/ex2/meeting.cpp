#include "stdafx.h"
#include "meeting.h"


meeting::meeting(const std::string subject, const std::time_t startHour, const std::time_t endHour)
{

	if (std::gmtime(&startHour)->tm_wday == std::gmtime(&endHour)->tm_wday && startHour < endHour)
	{
		this->subject = subject;
		this->startHour = startHour;
		this->endHour = endHour;
	}
	//if (startHour < 0 || startHour >23 || endHour < 0 || endHour >23 || endHour >= startHour)
	throw incorrect_meeting_error;
	
}

meeting::~meeting() {}

void meeting::setSubject(const std::string subject)
{
	this->subject = subject;
}

void meeting::setStartHour(const std::time_t startHour)
{
	this->startHour = startHour;
}

void meeting::setEndHour(const std::time_t endHour)
{
	this->endHour = endHour;
}




const std::string meeting::getSubject() const
{
	return subject;
}

const std::time_t meeting::getStartHour() const
{
	return startHour;
}

const std::time_t meeting::getEndHour() const
{
	return endHour;
}

bool meeting::operator==( const meeting& a )
{
	return (a.getStartHour() == startHour) && (a.getEndHour() == endHour) && (a.getSubject() == subject);
}



