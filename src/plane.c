#include "minirt.h"

float hit_plane(t_plane *plan, t_ray *ray)
{
    float denom;
    float t;
    t_vec3 co;

    denom = dot(plan->normal, ray->dir);
    if (fabs(denom) > 0.0001)
    {
        co = vec3_substract((t_vec3){plan->x, plan->y, plan->z}, ray->origin);
        t = dot(co, plan->normal) / denom;
        if (t >= 0)
            return t;
    }
    return 0.0;
}
