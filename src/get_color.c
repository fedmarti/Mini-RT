#include "minirt.h"

float hit_sphere(t_sphere sphere, t_vec3 raydir, t_vec3 camera)
{
	t_vec3 oc;
    float a;
    float b; 
    float c;
	float discr;

	sphere.x = 0;
	sphere.y = 10;
	sphere.z = 40;
	sphere.diameter = 20;
	oc = (t_vec3){camera.x - sphere.x, camera.y - sphere.y, camera.z - sphere.z};
	a = dot(raydir, raydir);
	b = 2.0 * dot(oc, raydir);
	c = dot(oc, oc) - (sphere.diameter/2) * (sphere.diameter/2);
    discr = b * b - 4 * a * c;
    if (discr < 0)
        return -1.0;
    else
        return(get_sphere_t((-b - sqrt(discr)) / (2*a), (-b + sqrt(discr)) / (2*a)));
}

float intersect_plane(t_plane plane, t_vec3 origin, t_vec3 raydir) {
    float denom;
	float t;
    t_vec3 co;

    denom = dot(vec3_normalize((t_vec3){plane.normal_x, plane.normal_y, plane.normal_z}), raydir);
    if (fabs(denom) > 0.0001)
	{
        co = vec3_substract((t_vec3){plane.x, plane.y, plane.z}, origin);
        t = dot(co, (t_vec3){plane.normal_x, plane.normal_y, plane.normal_z}) / denom;
        if (t >= 0 && raydir.y < 0)
            return t;
    }
    return -1.0;
}

int get_color(t_vec3 raydir, t_scene *scene) 
{
    float closest_t = INFINITY;
	float tmp_t = INFINITY;
    int color = 0x000000;
	t_cyl_utils data;
	
	tmp_t = hit_cyl(scene->shapes->shape.cylinder, 
	(t_vec3){scene->camera.x,scene->camera.y,scene->camera.z} , raydir, &data);
	if(tmp_t > 0)
	{
		if(data.flag == 1)
			return(0x600000);
		else if(data.flag == 2)
			return(0x888888);
		else if(data.flag == 3)
			return(0x444444);
	}
    tmp_t = hit_sphere(scene->shapes->shape.sphere, raydir, (t_vec3){scene->camera.x, scene->camera.y, scene->camera.z});
    if (tmp_t > 0 && tmp_t < closest_t)
    {
        closest_t = tmp_t;
        color = 0x00FF00;
    }
    tmp_t = intersect_plane(scene->shapes->shape.plane, (t_vec3){scene->camera.x, scene->camera.y, scene->camera.z}, raydir);
    if (tmp_t > 0 && tmp_t < closest_t)
    {
        closest_t = tmp_t;
        color = 0xFF0000;
    }

    return color;
}