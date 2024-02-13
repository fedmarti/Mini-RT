#include "minirt.h"
#define EPSILON 1e-6

int hit_sphere(t_vec3 center, float radius, t_vec3 ray_origin, t_vec3 ray_dir)
{
    t_vec3 origine_meno_center = {ray_origin.x - center.x, ray_origin.y - center.y, ray_origin.z - center.z};
    float a = dot(ray_dir, ray_dir);
    float b = 2.0 * dot(origine_meno_center, ray_dir);
    float c = dot(origine_meno_center, origine_meno_center) - radius * radius;
    float discriminante = b * b - 4 * a * c;
    return (discriminante > 0);
}

bool intersect_plane(t_plane plane, t_vec3 ray_origin, t_vec3 ray_dir, float* t)
{
    float denominatore = dot((t_vec3){plane.normal_x, plane.normal_y, plane.normal_z}, ray_dir);
    if (fabs(denominatore) > EPSILON)
	{
        t_vec3 originToplane = vec3_substract((t_vec3){plane.x, plane.y, plane.z}, ray_origin);
        *t = dot(originToplane, (t_vec3){plane.normal_x, plane.normal_y, plane.normal_z}) / denominatore;
        if (*t >= 0)
            return (ray_dir.y < 0);
    }
    return false;
}

int hit_cyl(t_cylinder cyl, t_vec3 ray_origin, t_vec3 ray_dir, int *flag)
{
	t_vec3 origin_meno_center = {ray_origin.x - cyl.x, ray_origin.y - cyl.y, ray_origin.z - cyl.z};
	float t0;
	float y0;
	float a = ray_dir.x * ray_dir.x + ray_dir.z * ray_dir.z;
	float b = 2.0 * (origin_meno_center.x * ray_dir.x + origin_meno_center.z * ray_dir.z);
	float c = origin_meno_center.x * origin_meno_center.x + origin_meno_center.z * origin_meno_center.z - (cyl.diameter / 2)  * (cyl.diameter / 2);
	float discriminante = b * b - 4 * a * c;

	if (discriminante < 0)
		return 0;

	t0 = (-b - sqrt(discriminante)) / (2 * a);
	if (t0 > 0)
	{
		y0 = ray_origin.y + t0 * ray_dir.y;
		if (y0 >= cyl.y && y0 <= cyl.y + cyl.height)
		{
			*flag = 1;
			return t0;
		}
	}

	t0 = (-b + sqrt(discriminante)) / (2 * a);
	if (t0 > 0)
	{
		y0 = ray_origin.y + t0 * ray_dir.y;
		if (y0 >= cyl.y && y0 <= cyl.y + cyl.height)
		{
			*flag = 0;
			return t0;
		}
	}
	return 0;
}