#pragma once

class meeting
{
public:
	meeting(const std::string subject, const std::time_t startHour, const std::time_t endHour);
	virtual ~meeting();

	void setSubject(const std::string subject);
	void setStartHour(const std::time_t startHour);
	void setEndHour(const std::time_t endHour);

	const std::string getSubject() const;
	const std::time_t getStartHour() const;
	const std::time_t getEndHour() const;
	
	bool operator== (const meeting& a);

	
private:
	std::string subject;
	std::time_t startHour;
	std::time_t endHour;
};
