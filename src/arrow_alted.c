/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_alted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:26:22 by shhuang           #+#    #+#             */
/*   Updated: 2024/04/15 00:57:20 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	alt_arrow(t_general *g, t_radians d_theta, t_radians d_phi)
{
	t_vec3		*v;
	t_radians	*theta;
	t_radians	*phi;
	t_vec3		new_v;

	if (g->selected == NULL \
	|| (g->selected->type != Cylinder && g->selected->type != Plane))
	{
		v = &g->scene->camera.dir;
		theta = &g->scene->camera.theta;
		phi = &g->scene->camera.phi;
	}
	else
		pointer_to_orientation(g->selected, &v, &theta, &phi);
	*theta = ft_clamp_d(*theta + d_theta, 0, M_PI);
	*phi = fmodf(*phi + d_phi, 2 * M_PI);
	new_v = vec3_from_sp(*theta, *phi, 1);
	printf("dir.x %f dir.y %f dir.z %f\n", new_v.x, new_v.y, new_v.z);
	*v = new_v;
}

void	alt_left_on(void *general)
{
	alt_arrow(general, 0, ROTATE_SPEED);
}

void	alt_up_on(void *general)
{
	alt_arrow(general, -ROTATE_SPEED, 0);
}

void	alt_right_on(void *general)
{
	alt_arrow(general, 0, -ROTATE_SPEED);
}

void	alt_down_on(void *general)
{
	alt_arrow(general, ROTATE_SPEED, 0);
}
