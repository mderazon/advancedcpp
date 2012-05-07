#include "stdafx.h"

calendar::calendar() 
{
	int i;
	for (i=0 ; i<7 ; i++)
		week[i].setID(i+1);
}


calendar::~calendar()
{
	delete[] this->week;
	
}

 void addAppoinment(int dayID, const apppointment& app)
{
	try
	{
		
	}

	catch (int e) 
	{

	}
}

 void removeAppointment(int dayID, apppointment& app)
{

}

void calendar::cleanCalander()
{

}

const apppointment& calendar::findAppointment( int dayID,float startHour )
{

}

void calendar::copyAppointment( apppointment app,float startHour )
{

}

void calendar::copyAppointment( apppointment app,day targetDay )
{

}

void calendar::printCalender() const
{

}
