#include "participant.h"
#include "meeting.h"

class extendedMeeting : public meeting
{
public:
	extendedMeeting( const std::string subject, const std::time_t startHour, const std::time_t endHour,std::list<participant> p );
	~extendedMeeting();
	virtual EMeetingType GetType() const;

	const std::list<participant>& getParticipants() const;

private:
	std::list<participant> participants; 
};


