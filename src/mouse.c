#include "minirt.h"


int on_click_event(int button, int x, int y, void *mouse)
{
	t_mouse *info;
	
	info = (t_mouse *)mouse;
	if(button == 1)
		info->pressed = pressed_left;
	else if(button == 2)
		info->pressed = pressed_right;
	else if(button == 3)
		info->pressed = pressed_middle;
	else if(button == 4)
		info->pressed = scroll_down;
	else if(button == 5)
		info->pressed = scroll_up;
	info->mouse_x = (float)x;
	info->mouse_y = (float)y;
    return 0;
}
