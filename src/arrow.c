/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:35:42 by shhuang           #+#    #+#             */
/*   Updated: 2024/04/15 01:36:08 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	move_cam(t_camera *camera, t_vec3 mov_dir)
{
	t_vec3	movement;

	movement = vec3_normalize((t_vec3){camera->dir.x, 0, camera->dir.z});
	if (mov_dir.x)
	{
		movement = vec3_from_sp(M_PI_2, \
		fmodf(camera->phi + (M_PI * (mov_dir.x < 0)), M_PI * 2), 1);
	}
	else if (mov_dir.z)
	{
		movement = vec3_from_sp(M_PI_2, \
		fmodf(camera->phi + (M_PI_2 * mov_dir.z), M_PI * 2), 1);
	}
	movement = vec3_scale(movement, STEPS);
	camera->x += movement.x;
	camera->y += movement.y;
	camera->z += movement.z;
}

void	left_on(void *general)
{
	t_general	*g;
	float		*x;

	g = (t_general *)general;
	if (g->selected == NULL)
	{
		move_cam(&g->scene->camera, (t_vec3){-1, 0, 0});
		// g->scene->camera.x -= cos(g->scene->camera.dir.y) * STEPS;
		// g->scene->camera.z -= sin(g->scene->camera.dir.y) * STEPS;
	}
	else
	{
		pointer_to_position(g->selected, &x, NULL, NULL);
		*x -= STEPS;
	}
}

void	up_on(void *general)
{
	t_general	*g;
	float		*z;

	g = (t_general *)general;
	if (g->selected == NULL)
	{
		move_cam(&g->scene->camera, (t_vec3){0, 0, 1});
		// g->scene->camera.x -= sin(g->scene->camera.dir.y) * STEPS;
		// g->scene->camera.z += cos(g->scene->camera.dir.y) * STEPS;
	}
	else
	{
		pointer_to_position(g->selected, NULL, NULL, &z);
		*z += STEPS;
	}
}

void	right_on(void *general)
{
	t_general	*g;
	float		*x;

	g = (t_general *)general;
	if (g->selected == NULL)
	{
		move_cam(&g->scene->camera, (t_vec3){1, 0, 0});
		// g->scene->camera.x += cos(g->scene->camera.dir.y) * STEPS;
		// g->scene->camera.z += sin(g->scene->camera.dir.y) * STEPS;
	}
	else
	{
		pointer_to_position(g->selected, &x, NULL, NULL);
		*x += STEPS;
	}
}

void	down_on(void *general)
{
	t_general	*g;
	float		*z;

	g = (t_general *)general;
	if (g->selected == NULL)
	{
		move_cam(&g->scene->camera, (t_vec3){0, 0, -1});
		// g->scene->camera.x += sin(g->scene->camera.dir.y) * STEPS;
		// g->scene->camera.z -= cos(g->scene->camera.dir.y) * STEPS;
	}
	else
	{
		pointer_to_position(g->selected, NULL, NULL, &z);
		*z -= STEPS;
	}
}
