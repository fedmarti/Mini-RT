/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <dsheng1993@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:11:02 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/23 01:39:50 by shhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"

int	main(int argc, char **argv)
{
	t_scene	*scene;
	t_window main_window;

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
	main_window = *load_window(&main_window);
	mlx_loop(main_window.init_ptr);
	free(scene);
}