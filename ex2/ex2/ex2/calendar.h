#include "day.h"

class calendar {
public:
	calendar();
	~calendar();

	day getDay(int dayID) const;
	void addMeeting( day d, meeting *m);
	void removeMeeting (day d,meeting *m_);
	void changeMeeting (day old_d, meeting *old_m, day new_d,meeting *new_m);

private:
	std::vector<day> week;
};