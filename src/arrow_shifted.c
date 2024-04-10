/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_shifted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:30:37 by shhuang           #+#    #+#             */
/*   Updated: 2024/04/10 21:57:17 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	shift_left_on(void *general)
{
	t_general	*g;
	int			diameter_point_pos;

	g = general;
	diameter_point_pos = 3;
	if (g->selected == NULL || g->selected->type == Plane)
		g->scene->camera.x--;
	else
	{
		if (g->selected->type == Cylinder)
			diameter_point_pos += 3;
		*((float *)g->selected + diameter_point_pos) -= 1;
		if (*((float *)g->selected + diameter_point_pos) < 0)
			*((float *)g->selected + diameter_point_pos) = 0.01;
	}
}

void	shift_up_on(void *general)
{
	t_general	*g;

	g = general;
	if (g->selected == NULL || g->selected->type == Plane)
		g->scene->camera.y++;
	else if (g->selected->type == Cylinder)
	{
		*((float *)g->selected + 7) += 1;
		if (*((float *)g->selected + 7) < 0)
			*((float *)g->selected + 7) = 0.01;
	}
}

void	shift_right_on(void *general)
{
	t_general	*g;
	int			diameter_point_pos;

	g = general;
	diameter_point_pos = 3;
	if (g->selected == NULL || g->selected->type == Plane)
		g->scene->camera.x++;
	else
	{
		if (g->selected->type == Cylinder)
			diameter_point_pos += 3;
		*((float *)g->selected + diameter_point_pos) += 1;
		if (*((float *)g->selected + diameter_point_pos) < 0)
			*((float *)g->selected + diameter_point_pos) = 0.01;
	}
}

void	shift_down_on(void *general)
{
	t_general	*g;
	float		*y;

	g = general;
	if (g->selected == NULL || g->selected->type == Plane)
		g->scene->camera.y--;
	else if (g->selected->type == Cylinder)
	{
		pointer_to_position(g->selected, NULL, &y, NULL);
		*y += STEPS;
		// if (*((float *)g->selected + 7) < 0)
			// *((float *)g->selected + 7) = 0.01;
	}
}
