#include "minirt.h"

int apply_ambient_light(int color, float intensity, unsigned int ambientColor)
{
    int c_rgb[3];
	int a_rgb[3];
    int i;
	int save_orig_color;

	i=0;
    c_rgb[0] = (color >> 16) & 0xFF;
    c_rgb[1] = (color >> 8) & 0xFF;
    c_rgb[2] = color & 0xFF;
    a_rgb[0] = (ambientColor >> 16) & 0xFF;
    a_rgb[1] = (ambientColor >> 8) & 0xFF;
    a_rgb[2] = ambientColor & 0xFF;
    while(i < 3)
    {
		save_orig_color = c_rgb[i] * intensity;
        c_rgb[i] = (int)(save_orig_color + a_rgb[i] * intensity);
        if(c_rgb[i] > 255)
            c_rgb[i] = 255;
		i++;
    }
    return (c_rgb[0] << 16) | (c_rgb[1] << 8) | c_rgb[2];
} 


void apply_ambient(t_scene *scene)
{
	int i;

	i = 0;
	while(i < scene->shape_n)
	{
		if(scene->shapes[i].type == Plane)
		{
			scene->shapes[i].shape.plane.color = 
			apply_ambient_light(scene->shapes[i].shape.plane.color, scene->ambient.ratio, scene->ambient.color);
		}
		else if(scene->shapes[i].type == Sphere)
		{
			scene->shapes[i].shape.sphere.color =
			apply_ambient_light(scene->shapes[i].shape.sphere.color, scene->ambient.ratio, scene->ambient.color);
		}
		else if(scene->shapes[i].type == Cylinder)
		{
			scene->shapes[i].shape.cylinder.color = 
			apply_ambient_light(scene->shapes[i].shape.cylinder.color, scene->ambient.ratio, scene->ambient.color);
		}
		i++;
	}
}