#include "stdafx.h"

class day {
public:
	day();
	day(int id);
	~day();

	virtual int getID() const;
	virtual void setID(int id);
	virtual void addAppointment(const apppointment& a);
	virtual void removeAppointment(const apppointment& a);
	virtual const apppointment& findAppointment(float StartHour) const;
	virtual const std::string& printDay() const;
	


private:
	int id;
	list<apppointment> apppointments;
	

};