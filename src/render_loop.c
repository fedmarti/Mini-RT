/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <dsheng1993@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 22:00:24 by fedmarti          #+#    #+#             */
/*   Updated: 2024/04/11 10:16:47 by shhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rotate_raydir(t_vec3 *raydir, t_vec3 camera)
{
	t_vec3	rotated_y;
	t_vec3	rotated_x;

	rotated_x = (t_vec3)
	{
		raydir->x,
		raydir->y * cos(camera.x) - raydir->z * sin(camera.x),
		raydir->y * sin(camera.x) + raydir->z * cos(camera.x)
	};
	rotated_y = (t_vec3)
	{
		rotated_x.x * cos(camera.y) - rotated_x.z * sin(camera.y),
		rotated_x.y,
		rotated_x.x * sin(camera.y) + rotated_x.z * cos(camera.y)
	};
	*raydir = (t_vec3)vec3_normalize(rotated_y);
}

void	render(t_scene *scene, t_viewport viewport, t_window *program)
{
	float	viewport_x;
	float	viewport_y;
	int		color;

	viewport.y = -1;
	while (++viewport.y < viewport.image_height)
	{
		viewport.x = 0;
		while (viewport.x < viewport.image_width)
		{
			viewport_x = (viewport.x - viewport.image_width / 2.0) \
			* (viewport.viewport_width / viewport.image_width);
			viewport_y = -(viewport.y - viewport.image_height / 2.0) \
			* (viewport.viewport_height / viewport.image_height);
			viewport.actual_raydir = (t_vec3){viewport_x, viewport_y, 1.0};
			rotate_raydir(&viewport.actual_raydir, (t_vec3) \
			{scene->camera.dir.x, scene->camera.dir.y, scene->camera.dir.z});
			color = get_color(viewport.actual_raydir, scene);
			program->img_data[(int)viewport.x + (int)viewport.y \
			* (int)viewport.image_width] = color;
			++viewport.x;
		}
	}
	mlx_put_image_to_window(program->init_ptr, program->window, \
	program->img_ptr, 0, 0);
}

int	render_loop(t_general *general)
{
	render(general->scene, general->viewport, &general->program);
	general->scene->camera.dir.x = fmax(MINPITCH, fmin(MAXPITCH, general->scene->camera.dir.x));
	return (0);
}
