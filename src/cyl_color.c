#include "minirt.h"

// static int calculate_cyl_extern(int color)
// {
// 	return(color);
// }

// static int calculate_cyl_intern(int color)
// {
// 	return(color);
// }

// static int calculate_cylinder_base(int color)
// {
// 	return(color);
// }

int calculate_cylinder_color(t_cylinder cyl, t_cyl_utils *data, t_scene *scene, t_vec3 raydir)
{
	t_vec3 hit_point;
	t_vec3 norm;

	hit_point = vec3_add((t_vec3){scene->camera.x, scene->camera.y, scene->camera.z}, vec3_scale(raydir, data->min_t));
	norm = vec3_normalize(vec3_substract(hit_point, (t_vec3){cyl.x, cyl.y, cyl.z}));
	return(loop_light(scene, hit_point, norm, cyl.color));
	if(data->flag == 1)
		return(loop_light(scene, hit_point, norm, cyl.color));
	if(data->flag == 2)
		return(loop_light(scene, hit_point, norm, cyl.color));
	if(data->flag == 3)
		return(loop_light(scene, hit_point, norm, cyl.color/2));
	return(0);
}
