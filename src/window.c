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



t_window *load_window(t_window *main_window, char *titlex, t_general *general)
{
	const int LEN = 30;
	char title[LEN+1];
	ft_bzero(title, sizeof(title));

	ft_strlcpy(title, "MiniRT: ", LEN);
	if(!ft_strrchr(titlex, '/'))
		ft_strlcat(title, titlex, LEN);
	else
		ft_strlcat(title, ft_strrchr(titlex, '/') +1, LEN);
	if(!ft_strncmp(&title[ft_strlen(title)-3], ".rt", 3))
		title[ft_strlen(title)-3] = 0;

	main_window->init_ptr = mlx_init();
	main_window->window = mlx_new_window(main_window->init_ptr,(unsigned int) WIN_WIDTH ,(unsigned int)WIN_HEIGHT, title);
	mlx_hook(main_window->window, KeyPress, KeyPressMask, handle_keypress, general);
	mlx_hook(main_window->window, KeyRelease, KeyReleaseMask, handle_keyrelease, general);
	mlx_hook(main_window->window, DestroyNotify, ButtonPressMask, close_x, main_window);
	save_window_info(main_window);
	return(main_window);
}
