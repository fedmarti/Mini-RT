/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:16:29 by fedmarti          #+#    #+#             */
/*   Updated: 2024/04/10 22:10:21 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <mlx_int.h>

int	close_x(t_general *general)
{
	t_scene		*scene;
	t_window	*program;

	scene = general->scene;
	program = &general->program;
	if (scene)
	{
		if (scene->shape_n && scene->shapes)
			free(scene->shapes);
		if (scene->light_n && scene->lights)
			free(scene->lights);
		free(scene);
	}
	if (program->window)
		mlx_destroy_window(program->init_ptr, program->window);
	if (program->img_ptr)
		mlx_destroy_image(program->init_ptr, program->img_ptr);
	if (program->init_ptr)
	{
		mlx_destroy_display(program->init_ptr);
		free(program->init_ptr);
	}
	exit(1);
	return (0);
}

void	save_window_info(t_window *main_window)
{
	if (WIN_HEIGHT < WIN_WIDTH)
		main_window->aspectratio = WIN_WIDTH / WIN_HEIGHT;
	else
		main_window->aspectratio = WIN_HEIGHT / WIN_WIDTH;
}

void	init_funct_pointer(t_general *general)
{
	general->handlers[0] = left_on;
	general->handlers[1] = up_on;
	general->handlers[2] = right_on;
	general->handlers[3] = down_on;
	general->handlers[4] = shift_left_on;
	general->handlers[5] = shift_up_on;
	general->handlers[6] = shift_right_on;
	general->handlers[7] = shift_down_on;
	general->handlers[8] = alt_left_on;
	general->handlers[9] = alt_up_on;
	general->handlers[10] = alt_right_on;
	general->handlers[11] = alt_down_on;
	general->special_key = Null;
}

static void	get_window_title(char *title, size_t title_size, char *filename)
{
	ft_bzero(title, title_size);
	ft_strlcpy(title, "MiniRT: ", WIN_NAME_LEN);
	if (!ft_strrchr(filename, '/'))
		ft_strlcat(title, filename, WIN_NAME_LEN);
	else
		ft_strlcat(title, ft_strrchr(filename, '/') + 1, WIN_NAME_LEN);
	if (!ft_strncmp(&title[ft_strlen(title)-3], ".rt", 3))
		title[ft_strlen(title) - 3] = 0;
}

t_window	*load_window(t_window *main_window, char *titlex, \
t_general *general)
{
	char	title[WIN_NAME_LEN + 1];

	get_window_title(title, sizeof(title), titlex);
	main_window->init_ptr = mlx_init();
	main_window->window = mlx_new_window(main_window->init_ptr, (unsigned int) \
	general->viewport.image_width, (unsigned)general->viewport.image_height, \
	title);
	main_window->img_ptr = mlx_new_image(main_window->init_ptr, \
	general->viewport.image_width, general->viewport.image_height);
	main_window->img_data = (int *) \
	mlx_get_data_addr(main_window->img_ptr, &main_window->bits_per_pixel, \
	&main_window->size_line, &main_window->endian);
	init_funct_pointer(general);
	mlx_hook(main_window->window, KeyPress, KeyPressMask, handle_keypress, \
	general);
	mlx_hook(main_window->window, KeyRelease, KeyReleaseMask, \
	handle_keyrelease, general);
	mlx_hook(main_window->window, DestroyNotify, ButtonPressMask, close_x, \
	general);
	save_window_info(main_window);
	return (main_window);
}
