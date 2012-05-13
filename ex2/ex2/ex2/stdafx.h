// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include "day.h"
#include "appointment.h"
#include "calendar.h"
#include "extendedAppointment.h"
using namespace std;

#define no_such_appointment_error 20;
#define conflicting_appointments_error 21;
#define noSuchDayError 22;
#define incorrectAppointmentError 23;

enum EAppointmentType
{
	E_BASE_APPOINTMENT,
	E_EXTENDED_APPOINTMENT
};

// TODO: reference additional headers your program requires here
