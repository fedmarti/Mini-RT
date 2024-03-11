/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_shifted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <dsheng1993@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:30:37 by shhuang           #+#    #+#             */
/*   Updated: 2024/03/11 21:33:14 by shhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	shift_left_on(void *general)
{
	t_general	*g;
	int			diameter_point_pos;

	g = general;
	diameter_point_pos = 3;
	if (g->selected == NULL || g->selected_type == Plane)
		g->scene->camera.x--;
	else
	{
		if (g->selected_type == Cylinder)
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
	if (g->selected == NULL || g->selected_type == Plane)
		g->scene->camera.y++;
	else if (g->selected_type == Cylinder)
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
	if (g->selected == NULL || g->selected_type == Plane)
		g->scene->camera.x++;
	else
	{
		if (g->selected_type == Cylinder)
			diameter_point_pos += 3;
		*((float *)g->selected + diameter_point_pos) += 1;
		if (*((float *)g->selected + diameter_point_pos) < 0)
			*((float *)g->selected + diameter_point_pos) = 0.01;
	}
}

void	shift_down_on(void *general)
{
	t_general	*g;

	g = general;
	if (g->selected == NULL || g->selected_type == Plane)
		g->scene->camera.y--;
	else if (g->selected_type == Cylinder)
	{
		*((float *)g->selected + 7) += 0;
		if (*((float *)g->selected + 7) < 0)
			*((float *)g->selected + 7) = 0.01;
	}
}
