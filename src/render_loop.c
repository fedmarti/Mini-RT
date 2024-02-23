#include "minirt.h"
void rotate_raydir(t_vec3 *raydir, t_vec3 camera)
{
    float cos_x; 
    float sin_x; 
    float cos_y; 
    float sin_y;
	t_vec3 rotatedY;
	t_vec3 rotatedX;

	cos_x = cos(camera.x);
	sin_x = sin(camera.x);
	cos_y = cos(camera.y);
	sin_y = sin(camera.y);
    rotatedX = (t_vec3){
        raydir->x,
        raydir->y * cos_x - raydir->z * sin_x,
        raydir->y * sin_x + raydir->z * cos_x
    };
    rotatedY = (t_vec3){
        rotatedX.x * cos_y - rotatedX.z * sin_y,
        rotatedX.y,
        -rotatedX.x * sin_y + rotatedX.z * cos_y
    };
    *raydir = (t_vec3)vec3_normalize(rotatedY);
}

void render(t_scene *scene, t_viewport viewport, t_window *program)
{
	viewport.x = 0;
	viewport.y = 0;
	while(viewport.y < viewport.image_height)
	{
		viewport.x = 0;
		while(viewport.x < viewport.image_width)
		{
			viewport.actual_raydir = 
			(t_vec3){(viewport.x - viewport.image_width /  2.0) * viewport.viewport_width / viewport.image_width,
			-(viewport.y - viewport.image_height / 2.0) * viewport.viewport_height / viewport.image_height, 1.0};
			rotate_raydir(&viewport.actual_raydir, (t_vec3){scene->camera.dir_x, scene->camera.dir_y, scene->camera.dir_z});
			int color = get_color(viewport.actual_raydir, scene);
			program->img_data[(int)viewport.x + (int)viewport.y * (int)viewport.image_width] = color;
			++viewport.x;
		}
		++viewport.y;
	}
	mlx_put_image_to_window(program->init_ptr, program->window, program->img_ptr, 0, 0);
}

int render_loop(t_general *general)
{
	render(general->scene, general->viewport, &general->program);
	return(0);
}