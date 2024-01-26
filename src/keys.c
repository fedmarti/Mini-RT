#include "../includes/minirt.h"

void left_on()
{
	printf("left!\n");
}
void up_on()
{
	printf("up!\n");
}
void right_on()
{
	printf("right!\n");
}
void down_on()
{
	printf("down!\n");
}

void (*handlers[])(void) = {left_on, up_on ,right_on, down_on};

int handle_keypress(int pressedKey, t_general *general)
{
	if(general->arrow == (enum arrow)pressedKey)
		return(0);
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
		general->special_key = Alt;
	else if(pressedKey == SHIFT_LEFT_KEY)
		general->special_key = Shift;
	if(pressedKey >= LEFT && pressedKey <= DOWN)
	{
		general->arrow = pressedKey;
		(*handlers[general->arrow - 65361])();
	}
	return(0);
}


int handle_keyrelease (int releasedKey, t_general *general)
{
	if(releasedKey == ALT_KEY && general->special_key == Alt)
		general->special_key = Null;
	else if(releasedKey == SHIFT_LEFT_KEY && general->special_key == Shift)
		general->special_key = Null;
	else if(general->arrow == (enum arrow)releasedKey)
	{
		general->arrow = Null_arrow;
		printf("release\n");
	}
	return(0);
}