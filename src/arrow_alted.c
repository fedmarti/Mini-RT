/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_alted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:26:22 by shhuang           #+#    #+#             */
/*   Updated: 2024/04/12 00:06:15 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	alt_left_on(void *general)
{
	t_general	*g;
	t_vec3		*v;

	g = (t_general *)general;
	if (g->selected == NULL)
		v = &g->scene->camera.dir;
	else if (g->selected->type == Cylinder)
		v = &g->selected->shape.cylinder.normal;
	else if (g->selected->type == Plane)
		v = &g->selected->shape.plane.normal;
	else
		v = &g->scene->camera.dir;
	*v = vec3_normalize(euler_rotate_zyx(*v, 0, 0, -ROTATE_SPEED));
}

void	alt_up_on(void *general)
{
	t_general	*g;
	t_vec3		*v;

	g = (t_general *)general;
	if (g->selected == NULL)
		v = &g->scene->camera.dir;
	else if (g->selected->type == Cylinder)
		v = &g->selected->shape.cylinder.normal;
	else if (g->selected->type == Plane)
		v = &g->selected->shape.plane.normal;
	else
		v = &g->scene->camera.dir;
	*v = vec3_normalize(euler_rotate_zyx(*v, 0, ROTATE_SPEED, 0));
}

void	alt_right_on(void *general)
{
	t_general	*g;
	t_vec3		*v;

	g = (t_general *)general;
	if (g->selected == NULL)
		v = &g->scene->camera.dir;
	else if (g->selected->type == Cylinder)
		v = &g->selected->shape.cylinder.normal;
	else if (g->selected->type == Plane)
		v = &g->selected->shape.plane.normal;
	else
		v = &g->scene->camera.dir;
	*v = vec3_normalize(euler_rotate_zyx(*v, 0.0f, 0.0f, ROTATE_SPEED));
}

void	alt_down_on(void *general)
{
	t_general	*g;
	t_vec3		*v;

	g = (t_general *)general;
	if (g->selected == NULL)
		v = &g->scene->camera.dir;
	else if (g->selected->type == Cylinder)
		v = &g->selected->shape.cylinder.normal;
	else if (g->selected->type == Plane)
		v = &g->selected->shape.plane.normal;
	else
		v = &g->scene->camera.dir;
	*v = vec3_normalize(euler_rotate_zyx(*v, 0, -ROTATE_SPEED, 0));
}
