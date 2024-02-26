#include "minirt.h"

float intersect_plane(t_plane plane, t_vec3 origin, t_vec3 raydir)
{
    float denom;
    float t;
    t_vec3 co;
    t_vec3 plane_normal;

    plane_normal = vec3_normalize((t_vec3){plane.normal_x, plane.normal_y, plane.normal_z});
    denom = dot(plane_normal, raydir);
    if (fabs(denom) > 0.0001)
    {
        co = vec3_substract((t_vec3){plane.x, plane.y, plane.z}, origin);
        t = dot(co, plane_normal) / denom;
        if (t >= 0)
            return t;
    }
    return 0.0;
}
