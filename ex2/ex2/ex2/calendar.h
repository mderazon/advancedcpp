#include "stdafx.h"

class calendar {
public:
	calendar();
	~calendar();

	virtual day* getDay(int dayID) const;
	virtual void addAppointment( day d, appointment *app);
	virtual void removeAppointment (day d,appointment *app);
private:
	day *week;


};