#include "stdafx.h"

class day {
public:
	day();
	day(int id);
	~day();

	virtual int getID() const;
	virtual void setID(int id);
	virtual void addAppointment(appointment* a);
	virtual void removeAppointment(appointment* a);
	virtual appointment& findAppointment(float StartHour);
	virtual const std::string& printDay() const;
	virtual void cleanDay();
	


private:
	int id;
	list<appointment*> apppointments;
	

};