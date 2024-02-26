#include "minirt.h"

t_vec3 calculate_lighting(t_vec3 hit_point, t_vec3 normal, t_vec3 base_col, t_light light)
{
    t_vec3 light_dir;
    float diff;
	
	light_dir = vec3_normalize(vec3_substract((t_vec3){light.x, light.y, light.z}, hit_point));
	diff = fmax(dot(normal, light_dir), 0.0);
    return (t_vec3)
	{
        base_col.x * light.brightness * diff,
        base_col.y * light.brightness * diff,
        base_col.z * light.brightness * diff
    };
}

int loop_light(t_scene *scene, t_vec3 hit_point, t_vec3 norm, int base_col)
{
    float rgb[3];
	t_vec3 base_color;
	int i;
	
	i = -1;
	rgb[0] = 0;
	rgb[1] = 0;
	rgb[2] = 0;
	base_color = (t_vec3)
	{
        ((base_col >> 16) & 0xFF) / 255.0f,
        ((base_col >> 8) & 0xFF) / 255.0f,
        (base_col & 0xFF) / 255.0f
    };
    while(++i < scene->light_n)
	{
        base_color = calculate_lighting(hit_point, norm, base_color, scene->lights[i]);
        rgb[0] += base_color.x;
        rgb[1] += base_color.y;
        rgb[2] += base_color.z;
    }
    int r = fmin(rgb[0] * 255.0f, 255.0f);
    int g = fmin(rgb[1] * 255.0f, 255.0f);
    int b = fmin(rgb[2] * 255.0f, 255.0f);
    return (r << 16) | (g << 8) | b;
}