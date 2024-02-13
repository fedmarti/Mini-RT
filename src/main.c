/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <dsheng1993@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:11:02 by fedmarti          #+#    #+#             */
/*   Updated: 2024/02/13 01:02:07 by shhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"
#include "rt_parsing.h"

//for debugging purposes
void	print_scene_content(t_scene *scene)
{
	if (!scene)
	{
		printf("scene is NULL!\n");
		return ;
	}
	
	const t_lighting	l = scene->ambient;
	const t_camera		c = scene->camera;
	const t_shape		*shapes = scene->shapes;
	const t_light		*lights = scene->lights;
	const char *shape_names[] = {"Plane", "Shere", "Cylinder", "Line"};

	printf("abient: ratio:%f, color: %X\n", l.ratio, l.color);
	printf("camera: x:%f, y:%f, z:%f, dir_x:%f, dir_y:%f, dir_z:%f, fov:%f\n", c.x, c.y, c.z, c.dir_x, c.dir_y, c.dir_z, c.fov_degrees);
	printf("\tn shapes:%u\n", scene->shape_n);
	for (unsigned int i = 0; i < scene->shape_n; i++)
	{
		printf("shape n.%u: type: %s\n", i, shape_names[shapes[i].type]);
		switch (shapes[i].type)
		{
		case Plane:
			;
			const t_plane	*plane = &shapes[i].shape.plane;
			printf(" x:%f, y:%f, z:%f, normal_x:%f, normal_y:%f, normal_z:%f, color:%X\n", plane->x, plane->y, plane->z, plane->normal_x, plane->normal_y, plane->normal_z, plane->color);
			break;
		case Sphere:
			;
			const t_sphere *sphere = &shapes[i].shape.sphere;
			printf(" x:%f, y:%f, z:%f, diameter:%f, color:%X\n", sphere->x, sphere->y, sphere->z, sphere->diameter, sphere->color);
			break ;
		case Cylinder:
			;
			const t_cylinder *cylinder = &shapes[i].shape.cylinder;
			printf(" x:%f, y:%f, z:%f, normal_x:%f, normal_y:%f, normal_z:%f, height:%f, diameter:%f, color:%X\n", cylinder->x, cylinder->y, cylinder->z, cylinder->normal_x, plane->normal_y, cylinder->normal_z, cylinder->height, cylinder->diameter, cylinder->color);
			break ; 
		default:
			printf("Haven't implemented this one yet\n");
			break ;
		}
	}
	printf("\tn lights:%u\n", scene->light_n);
	for (unsigned int i = 0; i < scene->light_n; i++)
	{
		printf("light n.%u:\n", i);
		printf(" x:%f, y:%f, z:%f, diameter:%f, color:%X\n", lights[i].x, lights[i].y, lights[i].z, lights[i].brightness, lights[i].color);
	}
}

int	main(int argc, char **argv)
{
	(void)argc;
	t_scene		*scene;
	t_general	general;

	general = (t_general){0};
	if (argc != 2)
	{
		write (2, "Wrong number of arguments\n", 26);
		return (1);
	}
	scene = parse_rt(argv[1]);
	if (!scene)
	{
		write (2, "Errors while parsing .rt file\n", 30);
		return (1);
	}
	print_scene_content(scene);
	init_viewport(&general, &scene->camera);
	general.window= *load_window(&general.window, argv[1], &general);
	render(&general, scene);
	mlx_loop(general.window.init_ptr);
	free_scene(scene);
}
