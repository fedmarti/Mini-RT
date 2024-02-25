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

	denom = dot((t_vec3){plane.normal_x, plane.normal_y, plane.normal_z}, raydir);
	if (fabs(denom) > 0.0001)
	{
		co = vec3_substract((t_vec3){plane.x, plane.y, plane.z}, origin);
		t = dot(co, (t_vec3){plane.normal_x, plane.normal_y, plane.normal_z}) / denom;
		if (t >= 0 && raydir.y < 0)
			return t;
	}
	return 0.0;
}

//secondo me conviene far salvarci uno struct hit con distanza, e puntatore all'oggetto colpito
int get_color(t_vec3 raydir, t_scene *scene)
{
	float closest_t = INFINITY;
	float tmp_t = INFINITY;
	int color = 0x000000;
	unsigned int i = 0;

	while (i < scene->shape_n)
	{

		if (scene->shapes[i].type == Sphere)
			tmp_t = hit_sphere(scene->shapes[i].shape.sphere, raydir, (t_vec3){scene->camera.x, scene->camera.y, scene->camera.z});
		else if (scene->shapes[i].type == Plane)
			tmp_t = intersect_plane(scene->shapes[i].shape.plane, (t_vec3){scene->camera.x, scene->camera.y, scene->camera.z}, raydir);
		else if (scene->shapes[i].type == Cylinder)
			color = color;
		if (tmp_t > 0 && tmp_t < closest_t)
		{
			closest_t = tmp_t;
			switch (scene->shapes[i].type)
			{
			case Plane:
				color = scene->shapes[i].shape.plane.color;
				break;
			case Sphere:
				color = scene->shapes[i].shape.sphere.color;
				break;
			case Cylinder:
				color = scene->shapes[i].shape.cylinder.color;
				break;
			default:
				color = 0;
				break;
			}
		}
		i++;
	}
	return color;
}
