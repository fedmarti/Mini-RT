/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:11:02 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/22 20:36:22 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"

int	main(int argc, char **argv)
{
	t_scene	*scene;

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
	//setup hooks
	//loop mlx
	free(scene);
}