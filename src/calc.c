#include "minirt.h"

float dot(t_vec3 u, t_vec3 v)
{
	return(u.x*v.x + u.y * v.y + u.z * v.z);
}

t_vec3	point_at_parameter(t_vec3 origin, t_vec3 raydirection, float t)
{
	return ((t_vec3){origin.x + t * raydirection.x, origin.y + t
		* raydirection.y, origin.z + t * raydirection.z});
}

float	distance(t_vec3 a, t_vec3 b)
{
	return (sqrt(dot(vec3_substract(a, b), vec3_substract(a, b))));
}

t_vec3	get_perpendicular_oc(t_cyl_utils *data)
{
	data->dot_oc_axis = dot(data->oc, data->axis_normalize);
	return ((t_vec3)vec3_substract(data->oc, vec3_scale(data->axis_normalize,
				data->dot_oc_axis)));
}

t_vec3	get_perpendicular_dir(t_cyl_utils *data)
{
	data->dot_dir_axis = dot(data->raydir, data->axis_normalize);
	return ((t_vec3)vec3_substract(data->raydir,
			vec3_scale(data->axis_normalize, data->dot_dir_axis)));
}