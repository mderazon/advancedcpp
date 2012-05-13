#include "stdafx.h"

class calendar {
public:
	calendar();
	~calendar();

	virtual day* getDay(int dayID) const;
	virtual void addAppointment (int dayID, float startHour, float endHour, std::string subject);


private:
	day *week;


};