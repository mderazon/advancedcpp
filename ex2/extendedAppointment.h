#include "stdafx.h"

class extendedAppointment : public appointment
{
public:
	extendedAppointment( const std::string subject, float startHour, float endHour,list<int> p );
	virtual ~extendedAppointment();
	const list<int>& getPeople() const;
	virtual EAppointmentType GetType() const;
private:
list<int> people; 

};


