#include "stdafx.h"
#include "calendar.h"
#include "extendedCalendar.h"
#include "participant.h"


using namespace std;

// converts a time in the format hh:mm into a time_t object. day is 1-7
std::time_t getTime(int day, std::string time)
{
	int h, m;
	sscanf_s(time.c_str(), "%d:%d", &h, &m);
	struct tm timeinfo;
	timeinfo.tm_hour = h;
	timeinfo.tm_min = m;
	timeinfo.tm_year = 2012;
	timeinfo.tm_mday = 12 + day;
	timeinfo.tm_sec = 0;
	timeinfo.tm_year = 112;
	timeinfo.tm_mon = 4;

	return std::mktime(&timeinfo);
}

// return day of the week from time_t type
int getDay(meeting* m)
{
	std::time_t t = m->getStartHour();
	struct tm *tm = std::localtime(&t);
	return tm->tm_wday + 1;
}

int runCalendarExample()
{
	// create a base calendar
	calendar* cal = new calendar();
	try
	{
		//create couple of base meetings
		meeting* m1 = new meeting("Subject 1", getTime(1, "10:00"),getTime(1, "12:00"));	// good meeting
		meeting* m2 = new meeting("Subject 2", getTime(1, "14:00"),getTime(1, "16:00"));	// good meeting
//		meeting* m3 = new meeting("Subject 3", getTime(1, "12:00"),getTime(1, "10:00"));	// bad meeting - end time < start time
		meeting* m4 = new meeting("Subject 4", getTime(1, "11:00"),getTime(1, "13:00"));	// bad meeting - conflicts with meeting 1
		meeting* m5 = new meeting("Subject 5", getTime(3, "10:00"),getTime(3, "12:00"));	// good meeting
		// add meetings to calendar
		cal->addMeeting(getDay(m1),m1);
		cal->addMeeting(getDay(m2),m2);
		//		cal->addMeeting(getDay(m3),m3);	// should raise INCORRECT_MEETING_VALUES_ERROR
		//		cal->addMeeting(getDay(m4),m4);	// should raise CONFLICTING_MEETINGS_ERROR
		cal->addMeeting(getDay(m5),m5);
		cout << cal->printCalendar();
		// remove meetings from calendar
		cout << "Removing a meeting from calendar" << endl;
		cal->removeMeeting(getDay(m1),m1);
		cout << cal->printCalendar();
		// show polymorphism 
		participant p1(1, "Moshe");
		std::list<participant> plist1;
		plist1.insert(plist1.begin(),p1);
		extendedMeeting* m6 = new extendedMeeting("Subject 6", getTime(7, "18:00"),getTime(7, "19:00"), plist1);	// good meeting
		cal->addMeeting(getDay(m6), m6);
		cout << cal->printCalendar();

	}
	catch (int exception)
	{
		if (exception == CONFLICTING_MEETINGS_ERROR)
		{
			cout << "Error: Conflicting meetings";
			exit(CONFLICTING_MEETINGS_ERROR);
		}
		else if (exception == INCORRECT_MEETING_VALUES_ERROR)
		{
			cout << "Error: Incorrect meeting info";
			exit(INCORRECT_MEETING_VALUES_ERROR);
		}
	}
	return 0;
}

int runExtendedCalendarExample()
{
	// create an extended calendar
	extendedCalendar* ecal = new extendedCalendar();	
	// create couple of participants
	participant p1(1, "Moshe");
	participant p2(2, "David");
	participant p3(3, "Simcha");
	participant p4(4, "Natalie");
	participant p5(5, "Shelly");
	std::list<participant> plist1;
	std::list<participant> plist2;
	std::list<participant> plist3;
	plist1.insert(plist1.begin(),p1);
	plist1.insert(plist1.begin(),p2);
	plist2.insert(plist2.begin(),p3);
	plist2.insert(plist2.begin(),p4);
	plist2.insert(plist2.begin(),p5);
	plist3.insert(plist3.begin(),p3);

	try
	{
		//create couple of meetings
		extendedMeeting* m1 = new extendedMeeting("Subject 1", getTime(1, "10:00"),getTime(1, "12:00"), plist1);	// good meeting
		extendedMeeting* m2 = new extendedMeeting("Subject 2", getTime(1, "10:00"),getTime(1, "12:00"), plist2);	// good meeting - different people
		extendedMeeting* m3 = new extendedMeeting("Subject 3", getTime(1, "11:00"),getTime(1, "12:00"), plist3);	// bad meeting - same poeple same time as m2
		extendedMeeting* m4 = new extendedMeeting("Subject 4", getTime(1, "14:00"),getTime(1, "16:00"), plist3);	// bad meeting - conflicts with meeting 1
		extendedMeeting* m5 = new extendedMeeting("Subject 5", getTime(3, "10:00"),getTime(3, "12:00"), plist1);	// good meeting
		// add meetings to calendar
		ecal->addMeeting(getDay(m1),m1);
		ecal->addMeeting(getDay(m2),m2);
//		ecal->addMeeting(getDay(m3),m3);	// should raise CONFLICTING_MEETINGS_ERROR
		ecal->addMeeting(getDay(m4),m4);	// should raise CONFLICTING_MEETINGS_ERROR
//		ecal->addMeeting(getDay(m5),m5);
		cout << ecal->printCalendar();
//		// remove meetings from calendar
		cout << "Removing a meeting from calendar" << endl;
		ecal->removeMeeting(getDay(m1),m1);
		cout << ecal->printCalendar();



	}
	catch (int exception)
	{
		if (exception == CONFLICTING_MEETINGS_ERROR)
		{
			cout << "Error: Conflicting meetings";
			exit(CONFLICTING_MEETINGS_ERROR);
		}
		else if (exception == INCORRECT_MEETING_VALUES_ERROR)
		{
			cout << "Error: Incorrect meeting info";
			exit(INCORRECT_MEETING_VALUES_ERROR);
		}
	}
	return 0;
}

int main()
{
	runCalendarExample();
	runExtendedCalendarExample();
}

