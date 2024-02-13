/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <dsheng1993@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 02:14:11 by shhuang           #+#    #+#             */
/*   Updated: 2024/02/13 01:04:06 by shhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int get_color(t_scene* scene, t_vec3 ray_direction)
{
	(void)scene;
	(void)ray_direction;
	return(0xFF00FF);
}

t_vec3 *v3(void *v)
{
	t_vec3 *new;
	new = (t_vec3 *)v;

	new->x = *(float *)(v);
    new->y = *(float *)(v + sizeof(float));
    new->z = *(float *)(v + 2 * sizeof(float));
	return(new);
}

void render(t_general* general, t_scene *scene)
{
	t_window* window;
	t_viewport* viewport;
	t_vec3 current_pixel_center;
	t_vec3 ray_direction;
	int x;
	int y;
	
	window = &general->window;
	viewport = &general->viewport;
	x = 0;
	y = 0;
	while (y < (int)viewport->image_height) 
	{
		x = 0;
		while (x < (int)viewport->image_width)
		{
			current_pixel_center.x = viewport->center_of_0_index_pixel.x + viewport->pixel_u * x;
			current_pixel_center.y = viewport->center_of_0_index_pixel.y + viewport->pixel_v * y;
			current_pixel_center.z = 0;
			ray_direction = vec3_substract(current_pixel_center, *(v3((void *)&scene->camera)));
			window->img_data[x + y * (int)viewport->image_width] = get_color(scene, ray_direction);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(general->window.init_ptr, general->window.win_ptr, window->img_ptr, 0, 0);
}