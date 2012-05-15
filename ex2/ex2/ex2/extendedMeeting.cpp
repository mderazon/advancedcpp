#include "stdafx.h"
#include "extendedMeeting.h"


extendedMeeting::extendedMeeting( const std::string subject, std::time_t startHour, std::time_t endHour,std::list<participant> p ) : meeting(subject,startHour,endHour)
{
	this->participants = p;
}

extendedMeeting::~extendedMeeting()
{
	
}

const std::list<participant>& extendedMeeting::getParticipants() const
{
	return this->participants;
}

//EAppointmentType extendedMeeting::GetType() const
//{
//	return E_EXTENDED_APPOINTMENT;
//}