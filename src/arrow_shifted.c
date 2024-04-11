/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_shifted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:30:37 by shhuang           #+#    #+#             */
/*   Updated: 2024/04/11 14:24:25 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	shift_left_on(void *general)
{
	t_general	*g;
	float		*size;

	g = general;
	if (g->selected == NULL || g->selected->type == Plane)
		g->scene->camera.x--;
	else
	{
		if (g->selected->type == Cylinder)
		{
			size = &g->selected->shape.cylinder.diameter;
		}
		else if (g->selected->type == Sphere)
			size = &g->selected->shape.sphere.diameter;
		else
			return ;
		*size -= 1;
		if (*size < 0)
			*size = 0.01;
	}
}

void	shift_up_on(void *general)
{
	t_general	*g;
	float		*y;

	g = general;
	if (g->selected == NULL)
		g->scene->camera.y++;
	else
	{
		pointer_to_position(g->selected, NULL, &y, NULL);
		*y += STEPS;
	}
}

void	shift_right_on(void *general)
{
	t_general	*g;
	float		*size;

	g = general;
	if (g->selected == NULL || g->selected->type == Plane)
		g->scene->camera.x++;
	else
	{
		if (g->selected->type == Cylinder)
		{
			size = &g->selected->shape.cylinder.diameter;
		}
		else if (g->selected->type == Sphere)
			size = &g->selected->shape.sphere.diameter;
		else
			return ;
		*size += (*size < MAX_SHAPE_SIZE);
	}
}

void	shift_down_on(void *general)
{
	t_general	*g;
	float		*y;

	g = general;
	if (g->selected == NULL)
		g->scene->camera.y--;
	else
	{
		pointer_to_position(g->selected, NULL, &y, NULL);
		*y -= STEPS;
	}
}
