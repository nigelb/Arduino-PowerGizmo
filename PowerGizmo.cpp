// Do not remove the include below
#include "PowerGizmo.h"

PowerGizmo::PowerGizmo(AB08XX *clock)
{
	this->clock = clock;
	if(this->clock != NULL)
	{
		init();
	}
}

void PowerGizmo::init()
{
	char magic_number[11];
	clock->readRAM(0, (uint8_t*)&magic_number, 0, strlen(power_gizmo_magic_number));
	if(strcmp(power_gizmo_magic_number, magic_number) != 0)
	{
		clock->writeRAM(0, (uint8_t*)power_gizmo_magic_number, 0, strlen(power_gizmo_magic_number));
	}
}

uint8_t PowerGizmo::set(ab08xx_tmElements_t &time){}
uint8_t PowerGizmo::set(time_t time){}

void PowerGizmo::get(ab08xx_tmElements_t &time)
{
	if(this->clock != NULL)
	{
		clock->read(time);
	}
}

time_t PowerGizmo::get()
{

}

uint8_t PowerGizmo::wakeUpAt(time_t wake_up_time)
{
	ab08xx_tmElements_t time;
	breakTime(wake_up_time, time);
	return wakeUpAt(time);
}

uint8_t PowerGizmo::wakeUpAt(ab08xx_tmElements_t &wake_up_time)
{
	if(this->clock == NULL)
	{
		return POWERGIZMO_OK;
	}
}

uint8_t PowerGizmo::powerDown()
{
	if(this->clock == NULL)
	{
		return POWERGIZMO_DUMMY_CLOCK;
	}
}

uint8_t wakeUpIn(ab08xx_tmElements_t wake_up_in)
{

}
uint8_t wakeUpIn(time_t wake_up_in)
{

}



