#include "minirt.h"

t_vec3 calculate_lighting(t_vec3 hit_point, t_vec3 normal, t_vec3 base_col, t_light light)
{
	t_vec3 light_dir;
	float diff;

	light_dir = vec3_normalize(vec3_substract((t_vec3){light.x, light.y, light.z}, hit_point));
	diff = fmax(dot(normal, light_dir), 0.0);
	return (t_vec3)
	{
		base_col.x * light.brightness * diff * (float)(*((unsigned char *)&light.color + 2)) / 255.0f,
		base_col.y * light.brightness * diff * (float)(*((unsigned char *)&light.color + 1)) / 255.0f,
		base_col.z * light.brightness * diff * (float)(*((unsigned char *)&light.color + 0)) / 255.0f
	};
}

int loop_light(t_scene *scene, t_vec3 hit_point, t_vec3 norm, int base_col)
{
	float rgb[3];
	t_vec3 base_color;
	t_vec3 temp;
	int i;

	i = -1;
	base_color = (t_vec3)
	{
		((base_col >> 16) & 0xFF) / 255.0f,
		((base_col >> 8) & 0xFF) / 255.0f,
		(base_col & 0xFF) / 255.0f
	};
	rgb[0] = base_color.x;
	rgb[1] = base_color.y;
	rgb[2] = base_color.z;
	while (++i < scene->light_n)
	{
		temp = calculate_lighting(hit_point, norm, base_color, scene->lights[i]);
		rgb[0] += temp.x;
		rgb[1] += temp.y;
		rgb[2] += temp.z;
	}
	int r = fmin(rgb[0] * 255.0f, 255.0f);
	int g = fmin(rgb[1] * 255.0f, 255.0f);
	int b = fmin(rgb[2] * 255.0f, 255.0f);
	return (r << 16) | (g << 8) | b;
}