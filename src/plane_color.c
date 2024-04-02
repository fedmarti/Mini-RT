#include "minirt.h"

t_vec3	plane_hit_norm(t_plane *plane, t_vec3 hit_point)
{
	return (vec3_normalize(vec3_substract(hit_point, (t_vec3){plane->x, plane->y, plane->z})));
}