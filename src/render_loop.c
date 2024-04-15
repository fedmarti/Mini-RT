/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 22:00:24 by fedmarti          #+#    #+#             */
/*   Updated: 2024/04/15 02:53:46 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//takes a raydir vector and rotates it according to camera orientation
//applying rotation matrices using the angles from the spherical coor. system
void	rotate_raydir(t_vec3 *raydir, t_camera *camera)
{
	t_vec3	rotated_y;
	t_vec3	rotated_x;

	rotated_x = (t_vec3)
	{
		raydir->x,
		raydir->y * cos(camera->theta - M_PI_2) - \
		raydir->z * sin(camera->theta - M_PI_2),
		raydir->y * sin(camera->theta - M_PI_2) + \
		raydir->z * cos(camera->theta - M_PI_2)
	};
	rotated_y = (t_vec3)
	{
		rotated_x.x * cos(camera->phi) - rotated_x.z * sin(camera->phi),
		rotated_x.y,
		rotated_x.x * sin(camera->phi) + rotated_x.z * cos(camera->phi)
	};
	*raydir = (t_vec3)vec3_normalize(rotated_y);
}

//creates a rectangular grid onto which the rendered image will be projected
//iterates through each cell and casts a ray for each one
void	viewport_cast_rays(t_scene *scene, t_viewport *vp, int *img_data)
{
	float	viewport_x;
	float	viewport_y;
	int		x;
	int		y;
	int		color;

	y = -1;
	while (++y < vp->image_height)
	{
		x = 0;
		while (x < vp->image_width)
		{
			viewport_x = (x - vp->image_width / 2.0) \
			* (vp->viewport_width / vp->image_width);
			viewport_y = -(y - vp->image_height / 2.0) \
			* (vp->viewport_height / vp->image_height);
			vp->actual_raydir = (t_vec3){viewport_x, viewport_y, 1.0};
			rotate_raydir(&vp->actual_raydir, &scene->camera);
			color = get_color(vp->actual_raydir, scene);
			img_data[(int)x + (int)y * (int)vp->image_width] = color;
			++x;
		}
	}
}

void	render(t_scene *scene, t_viewport *viewport, t_window *program)
{
	viewport_cast_rays(scene, viewport, program->img_data);
	mlx_put_image_to_window(program->init_ptr, program->window, \
	program->img_ptr, 0, 0);
}

int	render_loop(t_general *general)
{
	render(general->scene, &general->viewport, &general->program);
	return (0);
}
