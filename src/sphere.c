#include "minirt.h"

static float get_sphere_t(float t1, float t2)
{
    if (t1 < 0 && t2 < 0)
        return -1.0;
    if (t1 < 0)
		return t2;
    if (t2 < 0)
		return t1;
    return fmin(t1, t2);
}

float hit_sphere(t_sphere *sphere, t_vec3 origin, t_vec3 *raydir)
{
	t_vec3 oc;
	float a;
	float b;
	float c;
	float discr;

	oc = (t_vec3){origin.x - sphere->x, origin.y - sphere->y, origin.z - sphere->z};
	a = dot(*raydir, *raydir);
	b = 2.0 * dot(oc, *raydir);
	c = dot(oc, oc) - (sphere->diameter / 2) * (sphere->diameter / 2);
	discr = b * b - 4 * a * c;
	if (discr < 0)
		return -1.0;
	else
		return (get_sphere_t((-b - sqrt(discr)) / (2 * a), (-b + sqrt(discr)) / (2 * a)));
}
