#include "../includes/minirt.h"
#include <mlx_int.h>

int close_x(t_general *general)
{
	general->arrow = Null_arrow;
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
void left_on(void *general)
{
	(void)general;
	printf("left!\n");
}
void up_on(void *general)
{
	(void)general;
	static int i=0;
	printf("up! %d\n", i++);
}
void right_on(void *general)
{
	(void)general;
	printf("right!\n");
}
void down_on(void *general)
{
	(void)general;
	
	printf("down!\n");
}



int whilethat(t_general *general)
{
	if(general->arrow != Null_arrow)
    	(*general->handlers[general->arrow - 65361])(general);
    return 0;
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
	general->handlers[0] = left_on;
    general->handlers[1] = up_on;
    general->handlers[2] = right_on;
    general->handlers[3] = down_on;
	mlx_hook(main_window->window, KeyPress, KeyPressMask, handle_keypress, general);
	mlx_hook(main_window->window, KeyRelease, KeyReleaseMask, handle_keyrelease, general);
	//mlx_mouse_hook(main_window, ); SELECT
	mlx_loop_hook(general->program.init_ptr, whilethat, general);
	mlx_hook(main_window->window, DestroyNotify, ButtonPressMask, close_x, general);
	save_window_info(main_window);
	return(main_window);
}
