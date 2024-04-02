#include "minirt.h"

// static int calculate_cyl_extern(int color)
// {
// 	return(color);
// }

// static int calculate_cyl_intern(int color)
// {
// 	return(color);
// }

// static int calculate_cylinder_base(int color)
// {
// 	return(color);
// }

t_vec3	cylinder_hit_norm(t_cylinder *cyl, enum e_cyl_hit flag, t_vec3 ht_point)
{
	t_vec3 norm;

	if (flag == Inside_Surface || flag == Outside_Surface)
	{
		norm = vec3_normalize(vec3_substract(ht_point, \
		(t_vec3){cyl->x, cyl->y, cyl->z}));
		if (flag == Inside_Surface)
			return (vec3_invert(norm));
		return (norm);
	}
	if (flag == Base_Top)
		return (cyl->normal);
	else if (flag == Base_Bottom)
		return (vec3_invert(cyl->normal));
	return ((t_vec3){0});
}