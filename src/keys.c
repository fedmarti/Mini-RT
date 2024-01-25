#include "../includes/minirt.h"

int handle_keypress(int pressedKey, t_general *general)
{
	if(pressedKey == SPACE)
	{
		if(general->help_info == false)
			general->help_info = true;
		else
			general->help_info = false;
		return(0);
	}
	else if (pressedKey == ESC)
		close_x();
	else if(pressedKey == ALT_KEY)
		general->on_hold = Alt;
	else if(pressedKey == SHIFT_LEFT_KEY)
		general->on_hold = Shift;
	return(0);
}


int handle_keyrelease (int releasedKey, t_general *general)
{
	if(releasedKey == ALT_KEY && general->on_hold == Alt)
	{
		general->on_hold = Null;
	}
	else if(releasedKey == SHIFT_LEFT_KEY && general->on_hold == Shift)
	{
		general->on_hold = Null;
	}
	return(0);
}