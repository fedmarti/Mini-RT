/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:11:02 by fedmarti          #+#    #+#             */
/*   Updated: 2024/04/05 21:19:39 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"
#include "rt_parsing.h"

int	main(int argc, char **argv)
{
	t_scene		*scene;
	t_general	general;

	general = (t_general){0};
	if (argc != 2)
		return (write (2, "Wrong number of arguments\n", 26));
	scene = parse_rt(argv[1]);
	if (!scene)
		return (write (2, "Errors while parsing .rt file\n", 30));
	general.scene = scene;
	init_viewport(&general, &scene->camera);
	general.program = *load_window(&general.program, argv[1], &general);
	apply_ambient(scene);
	mlx_loop_hook(general.program.init_ptr, render_loop, &general);
	mlx_mouse_hook(general.program.window, on_click_event, &general);
	mlx_loop(general.program.init_ptr);
	free_scene(scene);
}
