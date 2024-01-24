#include "../includes/minirt.h"
int handle_keypress(int pressedKey, t_keys *status)
{
	if(pressedKey == SPACE)
	{
		if(status->help_info == false)
			status->help_info = true;
		else
			status->help_info = false;
		return(0);
	}
	if (pressedKey == ESC)
		close_x();
	else if(pressedKey == ALT_KEY)
		status->ctrl = true;
	else if(pressedKey == SHIFT_LEFT_KEY)
		status->shift = true;
	// else if(pressedKey == UP)
	// 	status->arr_up = true;
	// else if(pressedKey == DOWN)
	// 	status->arr_down = true;
	// else if(pressedKey == LEFT)
	// 	status->arr_left = true;
	// else if(pressedKey == RIGHT)
	// 	status->arr_right = true;
	else
		status->count_pressed --;
	status->count_pressed++;
	printf("%d\n", status->count_pressed);
	printf("%d\n", pressedKey);
	fflush(stdout);
	return(0);
}


int handle_keyrelease (int releasedKey, t_keys *status)
{
	if (releasedKey == ESC)
		close_x();
	else if(releasedKey == ALT_KEY)
		status->ctrl = false;
	else if(releasedKey == SHIFT_LEFT_KEY)
		status->shift = false;

	if ((releasedKey == ALT_KEY || releasedKey == SHIFT_LEFT_KEY))
    status->count_pressed--;
	
	printf("%d", status->count_pressed);
	fflush(stdout);
}