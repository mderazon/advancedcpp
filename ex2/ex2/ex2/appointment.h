#include "stdafx.h"

class apppointment {
public:
	apppointment();
	apppointment(const std::string subject, float startHour, float endHour);
	~apppointment();

	virtual void setSubject(const std::string subject);
	virtual void setStartHour(const float startHour);
	virtual void setEndHour(const float endHour);
	

	virtual const std::string& getSubject() const;
	virtual const float getStartHour() const;
	virtual const float getEndHour() const;
	
	bool operator== (const apppointment& a);
	

private:
	std::string subject;
	float startHour;
	float endHour;


};