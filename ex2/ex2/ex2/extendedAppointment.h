#include "stdafx.h"

class extendedAppointment : public appointment
{
public:
	extendedAppointment::extendedAppointment( const std::string subject, float startHour, float endHour,list<int> p );
	const list<int>& getPeople() const;
private:
list<int> people; 

};


