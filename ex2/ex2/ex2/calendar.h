#include "stdafx.h"

class calendar {
public:
	calendar();
	~calendar();

	virtual void addAppoinment(int dayId, const apppointment& app);
	virtual void removeAppointment(int dayID, apppointment& app);
	virtual void cleanCalander();
	virtual const apppointment& findAppointment(int dayID,float startHour);
	virtual void copyAppointment(apppointment app,float startHour); //copies the app to the same days given hour
	virtual void copyAppointment(apppointment app,day targetDay);
	virtual void printCalender() const;



private:
	day week[7];
	


};