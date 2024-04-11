/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <dsheng1993@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:35:42 by shhuang           #+#    #+#             */
/*   Updated: 2024/04/11 17:06:39 by shhuang          ###   ########.fr       */
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
		g->scene->camera.x += sin(g->scene->camera.y) * STEPS;
		g->scene->camera.z -= cos(g->scene->camera.y) * STEPS;
		g->scene->camera.dir.y = fmod(g->scene->camera.dir.y, 2.0 * M_PI);
		if (g->scene->camera.dir.x < MINPITCH)
			g->scene->camera.dir.x = MINPITCH;
		else if (g->scene->camera.dir.x > MAXPITCH)
			g->scene->camera.dir.x = MAXPITCH;
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
	float		*y;

	g = (t_general *)general;
	if (g->selected == NULL)
	{
		g->scene->camera.x -= cos(g->scene->camera.y) * STEPS;
		g->scene->camera.z -= sin(g->scene->camera.y) * STEPS;
		g->scene->camera.dir.y = fmod(g->scene->camera.dir.y, 2.0 * M_PI);
		if (g->scene->camera.dir.x < MINPITCH)
			g->scene->camera.dir.x = MINPITCH;
		else if (g->scene->camera.dir.x > MAXPITCH)
			g->scene->camera.dir.x = MAXPITCH;
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
		g->scene->camera.x -= sin(g->scene->camera.y) * STEPS;
		g->scene->camera.z += cos(g->scene->camera.y) * STEPS;
		g->scene->camera.dir.y = fmod(g->scene->camera.dir.y, 2.0 * M_PI);
		if (g->scene->camera.dir.x < MINPITCH)
			g->scene->camera.dir.x = MINPITCH;
		else if (g->scene->camera.dir.x > MAXPITCH)
			g->scene->camera.dir.x = MAXPITCH;
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
		g->scene->camera.x += cos(g->scene->camera.y) * STEPS;
		g->scene->camera.z += sin(g->scene->camera.y) * STEPS;
		g->scene->camera.dir.y = fmod(g->scene->camera.dir.y, 2.0 * M_PI);
		if (g->scene->camera.dir.x < MINPITCH)
			g->scene->camera.dir.x = MINPITCH;
		else if (g->scene->camera.dir.x > MAXPITCH)
			g->scene->camera.dir.x = MAXPITCH;
	}
	else
	{
		pointer_to_position(g->selected, NULL, &y, NULL);
		*y -= STEPS;
	}
}
