#include "stdafx.h"

class calendar {
public:
	calendar();
	~calendar();

	virtual day* getDay(int dayID) const;


private:
	day *week;


};