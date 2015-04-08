// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef _PowerGizmo_H_
#define _PowerGizmo_H_

#include "Arduino.h"
#include "AB08XX.h"


static const char* power_gizmo_magic_number = "PowerGizmo";

#define POWERGIZMO_OK 1
#define POWERGIZMO_DUMMY_CLOCK 2


class PowerGizmo
{
private:
	AB08XX *clock;
	void init();
public:
	PowerGizmo(AB08XX *clock);
	uint8_t set(ab08xx_tmElements_t &time);
	uint8_t set(time_t time);

	void get(ab08xx_tmElements_t &time);
	time_t get();

	uint8_t wakeUpAt(time_t wake_up_time);
	uint8_t wakeUpAt(ab08xx_tmElements_t &wake_up_time);
	uint8_t wakeUpIn(ab08xx_tmElements_t &wake_up_in);
	uint8_t wakeUpIn(time_t wake_up_in);
	uint8_t powerDown();
};


#endif /* _PowerGizmo_H_ */
