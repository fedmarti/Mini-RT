#include "minirt.h"

float hit_sphere(t_sphere sphere, t_vec3 raydir, t_vec3 camera)
{
	t_vec3 oc;
	float a;
	float b;
	float c;
	float discr;

	oc = (t_vec3){camera.x - sphere.x, camera.y - sphere.y, camera.z - sphere.z};
	a = dot(raydir, raydir);
	b = 2.0 * dot(oc, raydir);
	c = dot(oc, oc) - (sphere.diameter / 2) * (sphere.diameter / 2);
	discr = b * b - 4 * a * c;
	if (discr < 0)
		return -1.0;
	else
		return (get_sphere_t((-b - sqrt(discr)) / (2 * a), (-b + sqrt(discr)) / (2 * a)));
}

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

int get_color(t_vec3 raydir, t_scene *scene)
{
	float closest_t = INFINITY;
	float tmp_t = INFINITY;
	int color = 0x000000;
	unsigned int i = 0;
	int 	closest_shape;
	t_cyl_utils data;
	void *actual_shape;

	while (i < scene->shape_n)
	{
		if (scene->shapes[i].type == Sphere)
			tmp_t = hit_sphere(scene->shapes[i].shape.sphere, raydir, (t_vec3){scene->camera.x, scene->camera.y, scene->camera.z});
		else if (scene->shapes[i].type == Plane)
			tmp_t = intersect_plane(scene->shapes[i].shape.plane, (t_vec3){scene->camera.x, scene->camera.y, scene->camera.z}, raydir);
		else if (scene->shapes[i].type == Cylinder)
			tmp_t = hit_cyl(scene->shapes[i].shape.cylinder, (t_vec3){scene->camera.x, scene->camera.y, scene->camera.z}, raydir, &data);
		if (tmp_t > 0 && tmp_t < closest_t)
		{
			closest_t = tmp_t;
			switch (scene->shapes[i].type)
			{
			case Plane:
				actual_shape = (void *)&scene->shapes[i].shape.plane;
				closest_shape = Plane;
				color = scene->shapes[i].shape.plane.color;
				break;
			case Sphere:
				actual_shape = (void *)&scene->shapes[i].shape.sphere;
				closest_shape = Sphere;
				color = scene->shapes[i].shape.sphere.color;
				break;
			case Cylinder:
				actual_shape = (void *)&scene->shapes[i].shape.cylinder;
				closest_shape = Cylinder;
				color = scene->shapes[i].shape.cylinder.color;
				break;
			default:
				break;
			}
		}
		i++;
	}
	if(closest_shape == Cylinder)
	{
		color = calculate_cylinder_color(*((t_cylinder *)actual_shape), &data, color);
		closest_shape = -1;
	}
	else if(closest_shape == Plane)
	{
		color = color;
		closest_shape = -1;
	}
	else if(closest_shape == Sphere)
	{
		color = color;
		closest_shape = -1;
	}
	return color;
}