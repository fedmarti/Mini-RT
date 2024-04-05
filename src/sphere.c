/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   sphere.c										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: fedmarti <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/04/05 21:55:38 by fedmarti		  #+#	#+#			 */
/*   Updated: 2024/04/05 21:55:42 by fedmarti		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "minirt.h"

static float	get_sphere_t(float t1, float t2)
{
	if (t1 < 0 && t2 < 0)
		return (-1.0);
	if (t1 < 0)
		return (t2);
	if (t2 < 0)
		return (t1);
	return (fmin(t1, t2));
}

float	hit_sphere(t_sphere *sphere, t_ray *ray)
{
	t_vec3	oc;
	float	a;
	float	b;
	float	c;
	float	discr;

	oc = (t_vec3){ray->origin.x - sphere->x, \
	ray->origin.y - sphere->y, ray->origin.z - sphere->z};
	a = dot(ray->dir, ray->dir);
	b = 2.0 * dot(oc, ray->dir);
	c = dot(oc, oc) - (sphere->diameter / 2) * (sphere->diameter / 2);
	discr = b * b - 4 * a * c;
	if (discr < 0)
		return (-1.0);
	else
		return (get_sphere_t((-b - sqrt(discr)) / (2 * a), \
		(-b + sqrt(discr)) / (2 * a)));
}
