/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:35:42 by shhuang           #+#    #+#             */
/*   Updated: 2024/04/05 21:07:46 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	left_on(void *general)
{
	t_general	*g;
	float		*x;

	g = (t_general *)general;
	if (g->selected == NULL)
	{
		g->scene->camera.x -= cos(g->scene->camera.y) * STEPS;
		g->scene->camera.z -= sin(g->scene->camera.y) * STEPS;
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
	t_vec3		movement_vector;
	float		*y;

	g = (t_general *)general;
	if (g->selected == NULL)
	{
		movement_vector = vec3_scale(g->scene->camera.dir, STEPS);
		g->scene->camera.x += movement_vector.x;
		g->scene->camera.y += movement_vector.y;
		g->scene->camera.z += movement_vector.z;
	}
	else
	{
		pointer_to_position(g->selected, NULL, &y, NULL);
		*y += STEPS;
	}
}

void	right_on(void *general)
{
	t_general	*g;
	float		*x;

	g = (t_general *)general;
	if (g->selected == NULL)
	{
		g->scene->camera.x += cos(g->scene->camera.y) * STEPS;
		g->scene->camera.z += sin(g->scene->camera.y) * STEPS;
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
	float		*y;

	g = (t_general *)general;
	if (g->selected == NULL)
	{
		g->scene->camera.x += sin(g->scene->camera.y) * STEPS;
		g->scene->camera.z -= cos(g->scene->camera.y) * STEPS;
	}
	else
	{
		pointer_to_position(g->selected, NULL, &y, NULL);
		*y -= STEPS;
	}
}
