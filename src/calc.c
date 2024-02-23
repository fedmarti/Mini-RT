#include "minirt.h"

float dot(t_vec3 u, t_vec3 v)
{
	return(u.x*v.x + u.y * v.y + u.z * v.z);
}

float get_sphere_t(float t1, float t2)
{
    if (t1 < 0 && t2 < 0)
        return -1.0;
    if (t1 < 0)
		return t2;
    if (t2 < 0)
		return t1;
    return fmin(t1, t2);
}