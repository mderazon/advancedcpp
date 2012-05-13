#include "stdafx.h"

class calendar {
public:
	calendar();
	~calendar();

	virtual day* getDay(int dayID) const;
	void addAppointment( day d, appointment *app);
	void removeAppointment (day d,appointment *app);
private:
	day *week;


};