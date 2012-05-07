#include "stdafx.h"


day::day(int id) 
{
	this->id=id;
}

int day::getID() const 
{
	return this->id;
}

const std::string& day::printDay() const
{
	std::stringstream s;
	int i;
	s << "Day Id:" << this->id << "\n";
	list<apppointment>::const_iterator cii;
	for(cii=apppointments.begin(), i=1; cii!=apppointments.end(); cii++,i++)
		s<<i<<". Subject: "<< cii->getSubject() << "\tTime: " << cii->getStartHour() << " - " << cii->getEndHour << "\n";
	return s.str();
}

const apppointment& day::findAppointment( float StartHour ) const
{
	list<apppointment>::const_iterator cii;
	for(cii=apppointments.begin(); cii!=apppointments.end(); cii++)
		if (cii->getStartHour() == StartHour)
			return *cii;
	throw no_such_appointment_error;
}

void day::removeAppointment(const apppointment& a)
{
	apppointments.remove(a);
			
}

void day::addAppointment( const apppointment& a)
{
	list<apppointment>::const_iterator cii;
	for(cii=apppointments.begin(); cii!=apppointments.end(); cii++)
			if ((a.getStartHour() > cii->getStartHour()) && (a.getStartHour() < cii->getEndHour())) || ((a.getEndHour() > cii->getStartHour()) && (a.getEndHour() < cii->getEndHour()))
				throw conflicting_appointments_error;
		apppointments.insert(cii,a);
		

}

void day::setID( int id )
{
	this->id = id;
}
