#include "minirt.h"

int on_click_event(int button, int x, int y, t_mouse *info)
{
	if(button == CLK_LEFT)
	{
		info->mouse_x = (float)x;
		info->mouse_y = (float)y;
		// selected_obj = ray_hit(x, y, scene);
    }
	return 0;
}
