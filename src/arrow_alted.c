/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_alted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <dsheng1993@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:26:22 by shhuang           #+#    #+#             */
/*   Updated: 2024/04/11 10:10:11 by shhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define ROTATE_SPEED 0.005f

void	alt_left_on(void *general)
{
	t_general	*g;

	g = (t_general *)general;
	if (g->selected == NULL || g->selected->type == Sphere)
		g->scene->camera.dir.y += ROTATE_SPEED;
	else
		*((float *)g->selected + 4) += -ROTATE_SPEED;
}

void	alt_up_on(void *general)
{
	t_general	*g;

	g = (t_general *)general;

	if (g->selected == NULL || g->selected->type == Sphere)
	{
		g->scene->camera.dir.x -= ROTATE_SPEED;
	}
	else
		*((float *)g->selected + 5) += ROTATE_SPEED;
}

void	alt_right_on(void *general)
{
	t_general	*g;

	g = (t_general *)general;

	if (g->selected == NULL || g->selected->type == Sphere)
		g->scene->camera.dir.y -= ROTATE_SPEED;
	else
		*((float *)g->selected + 4) += ROTATE_SPEED;
}

void	alt_down_on(void *general)
{
	t_general	*g;

	g = (t_general *)general;
	if (g->selected == NULL || g->selected->type == Sphere)
		g->scene->camera.dir.x += ROTATE_SPEED;
	else
		*((float *)g->selected + 5) += -ROTATE_SPEED;
}
