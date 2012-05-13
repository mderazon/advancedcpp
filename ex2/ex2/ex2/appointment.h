#include "stdafx.h"

class appointment {
public:
	appointment();
	appointment(const std::string subject, float startHour, float endHour);
	virtual ~appointment();

	virtual void setSubject(const std::string subject);
	virtual void setStartHour(const float startHour);
	virtual void setEndHour(const float endHour);
	

	virtual const std::string& getSubject() const;
	virtual const float getStartHour() const;
	virtual const float getEndHour() const;
	
	bool operator== (const appointment& a);
	

private:
	std::string subject;
	float startHour;
	float endHour;


};