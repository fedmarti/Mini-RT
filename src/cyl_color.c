#include "minirt.h"

static int calculate_cyl_extern(int color)
{
	return(color);
}

static int calculate_cyl_intern(int color)
{
	return(color);
}

static int calculate_cylinder_base(int color)
{
	return(color);
}

int calculate_cylinder_color(t_cylinder cyl, t_cyl_utils *data, int color)
{
	(void) cyl;
	if(data->flag == 1)
		return(calculate_cyl_extern(color));
	if(data->flag == 2)
		return(calculate_cyl_intern(color));
	if(data->flag == 3)
		return(calculate_cylinder_base(color/2));
	return(0);
}
