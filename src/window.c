#include "../includes/minirt.h"

int close_x()
{
	//LIBERA MEMORIA
	exit(1);
	return(0);
}

void save_window_info(t_window *main_window)
{
	if (WIN_HEIGHT < WIN_WIDTH)
		main_window->aspectratio = WIN_WIDTH / WIN_HEIGHT;
	else
		main_window->aspectratio = WIN_HEIGHT / WIN_WIDTH;
}

t_window *load_window(t_window *main_window, char *title, t_keys *keys_status)
{
	init_status(keys_status);
	main_window->init_ptr = mlx_init();
	main_window->window = mlx_new_window(main_window->init_ptr,(unsigned int) WIN_WIDTH ,(unsigned int)WIN_HEIGHT, title);
	mlx_hook(main_window->window, KeyPress, KeyPressMask, handle_keypress, keys_status);
	mlx_hook(main_window->window, KeyRelease, KeyReleaseMask, handle_keyrelease, keys_status);
	mlx_hook(main_window->window, DestroyNotify, ButtonPressMask, close_x, main_window);
	save_window_info(main_window);
	return(main_window);
}