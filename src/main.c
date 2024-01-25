/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <dsheng1993@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:11:02 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/25 18:47:19 by shhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"

int	main(int argc, char **argv)
{
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
	general.program = *load_window(&general.program, argv[1], &general);
	mlx_mouse_hook(general.program.window, on_click_event, &general.mouse);
	mlx_loop(general.program.init_ptr);
	free(scene);
}