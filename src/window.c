#include "../includes/minirt.h"

static int close_x()
{
	//LIBERA MEMORIA
	exit(1);
	return(0);
}

int ft_handle_keypress(int pressedKey)
{
	if (pressedKey == ESC)
		close_x();
	return(0);
}

static save_window_info(t_window *main_window)
{
	if (WIN_HEIGHT < WIN_WIDTH)
		main_window->aspectratio = WIN_WIDTH / WIN_HEIGHT;
	else
		main_window->aspectratio = WIN_HEIGHT / WIN_WIDTH;
}


t_window *load_window(t_window *main_window)
{
	main_window->init_ptr = mlx_init();
	main_window->window = mlx_new_window(main_window->init_ptr,(unsigned int) WIN_WIDTH ,(unsigned int)WIN_HEIGHT, "Minimain_window");
	mlx_hook(main_window->window, KeyPress, KeyPressMask, ft_handle_keypress, main_window);
	mlx_hook(main_window->window, DestroyNotify, ButtonPressMask, close_x, main_window);
	save_window_info(main_window);
	return(main_window);
}