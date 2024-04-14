/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:11:58 by fedmarti          #+#    #+#             */
/*   Updated: 2024/04/15 00:55:05 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	get_raydir(int x, int y, t_general *g)
{
	t_vec3	actual_raydir;
	float	view_x;
	float	view_y;

	view_x = (x - g->viewport.image_width / 2.0) \
	* (g->viewport.viewport_width / g->viewport.image_width);
	view_y = -(y - g->viewport.image_height / 2.0) \
	* (g->viewport.viewport_height / g->viewport.image_height);
	actual_raydir = (t_vec3){view_x, view_y, 1.0};
	rotate_raydir(&actual_raydir, &g->scene->camera);
	return (actual_raydir);
}

t_shape	*select_item(t_vec3 raydir, t_scene *scene)
{
	unsigned int	i;
	t_hit			rayhit;
	t_hit			temp_hit;
	t_ray			ray;

	ray.origin = (t_vec3){scene->camera.x, scene->camera.y, scene->camera.z};
	ray.dir = raydir;
	rayhit = (t_hit){INFINITY, NULL, Void_shape};
	i = -1;
	while (++i < scene->shape_n)
	{
		temp_hit = hit_shape(&scene->shapes[i], &ray, NULL);
		if (temp_hit.type != Void_shape && temp_hit.t < rayhit.t)
			rayhit = temp_hit;
	}
	return (rayhit.target);
}

int	on_click_event(int button, int x, int y, t_general *g)
{
	printf("x: %d ,y: %d\n", x, y);
	if (button == CLK_LEFT)
	{
		g->selected = select_item(get_raydir(x, y, g), g->scene);
		if (!g->selected)
			return (0);
		if (g->selected->type == Plane)
		{
			printf("Plane\n");
		}
		if (g->selected->type == Sphere)
		{
			printf("Sphere\n");
		}
		if (g->selected->type == Cylinder)
		{
			printf("Cilinder\n");
		}
	}
	if (button == CLK_RIGHT)
	{
		g->selected = NULL;
	}
	return (0);
}
