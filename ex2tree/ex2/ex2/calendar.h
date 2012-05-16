#include "day.h"

class calendar {
public:
	calendar();
	~calendar();

	day getDay(int dayId) const;
	virtual void addMeeting( int dayId, meeting *m);
	virtual void removeMeeting (int dayId,meeting *m_);
	virtual void changeMeeting (int old_dayId, meeting *old_m, int new_dayId,meeting *new_m);

private:
	std::vector<day> week;
};