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

int calculate_cylinder_color(t_cylinder *cyl, t_cyl_utils *data, t_scene *scene, t_vec3 raydir)
{
    t_vec3 hit_point;
    t_vec3 norm;

    if(data->flag == Inside_Surface)
        return(cyl->color);
    hit_point = vec3_add((t_vec3){scene->camera.x, scene->camera.y, scene->camera.z}, vec3_scale(raydir, data->min_t));
	if(data->flag == Base)
	{
		if(data->base_is_top)
			norm = vec3_normalize((t_vec3){cyl->normal_x, cyl->normal_y, cyl->normal_z});
		else
			norm = vec3_normalize(vec3_invert((t_vec3){cyl->normal_x, cyl->normal_y, cyl->normal_z}));
	}
    else
        norm = vec3_normalize(vec3_substract(hit_point, (t_vec3){cyl->x, cyl->y, cyl->z}));
    return(loop_light(scene, hit_point, norm, cyl->color));
}