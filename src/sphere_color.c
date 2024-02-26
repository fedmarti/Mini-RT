#include "minirt.h"



int calculate_sphere_color(t_sphere sphere, t_scene *scene, t_vec3 raydir, float t)
{
	t_vec3 hit_point;
    t_vec3 norm; 
	int color;

	color = sphere.color;
	hit_point = vec3_add((t_vec3){scene->camera.x, scene->camera.y, scene->camera.z}, vec3_scale(raydir, t));
	norm = vec3_normalize(vec3_substract(hit_point, (t_vec3){sphere.x, sphere.y, sphere.z}));

	color = loop_light(scene, hit_point, norm, sphere.color);
	return color;
}