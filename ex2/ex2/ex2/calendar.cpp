#include "stdafx.h"

calendar::calendar() 
{
	week = new day[7];
}


calendar::~calendar()
{
	int i;
	for (i=0;i<7;i++)
		delete (week+i);
}


day* calendar::getDay( int dayID ) const
{
	if (dayID < 1 || dayID >7)
			throw noSuchDayError;
	return &(week[dayID-1]);
}
