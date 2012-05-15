#pragma once
#include "meeting.h"
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

	meeting& findMeeting(float StartHour) const;

	//std::string printDay();

	void cleanDay();

private:
	int id;
	std::list<meeting*> meetings;
};

