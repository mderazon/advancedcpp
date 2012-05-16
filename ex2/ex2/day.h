#pragma once
#include "meeting.h"
#include "extendedMeeting.h"

class day
{
public:
	day();
	day(int id);
	~day();

	int getID() const;

	void setID(int id);

	void addMeeting(meeting* m);

	void removeMeeting(meeting* m);

	meeting& findMeeting(std::time_t StartHour) const;

	std::list<meeting*> getMeetings() const;
	
	void cleanDay();

private:
	int id;
	std::list<meeting*> meetings;
};

