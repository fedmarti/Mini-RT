#include "minirt.h"

t_vec3	sphere_hit_norm(t_sphere *sphere, t_vec3 hit_point)
{
	return (vec3_normalize(vec3_substract(hit_point, (t_vec3){sphere->x, sphere->y, sphere->z})));
}