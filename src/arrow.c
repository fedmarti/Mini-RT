/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:35:42 by shhuang           #+#    #+#             */
/*   Updated: 2024/04/11 21:17:25 by fedmarti         ###   ########.fr       */
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
		g->scene->camera.x -= cos(g->scene->camera.dir.y) * STEPS;
		g->scene->camera.z -= sin(g->scene->camera.dir.y) * STEPS;
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
		g->scene->camera.x -= sin(g->scene->camera.dir.y) * STEPS;
		g->scene->camera.z += cos(g->scene->camera.dir.y) * STEPS;
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
		g->scene->camera.x += cos(g->scene->camera.dir.y) * STEPS;
		g->scene->camera.z += sin(g->scene->camera.dir.y) * STEPS;
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
		g->scene->camera.x += sin(g->scene->camera.dir.y) * STEPS;
		g->scene->camera.z -= cos(g->scene->camera.dir.y) * STEPS;
	}
	else
	{
		pointer_to_position(g->selected, NULL, NULL, &z);
		*z -= STEPS;
	}
}
