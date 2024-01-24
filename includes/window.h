#ifndef WINDOW_H
#define WINDOW_H

//KEYPRESS MACRO
# define WIN_WIDTH 720.0f
# define WIN_HEIGHT 480.0f

typedef struct s_window
{
	void	*init_ptr;
	void	*window;
	float	aspectratio;
} t_window;

typedef struct s_general_info
{
	t_mouse mouse;
	t_keys keys_status;
	t_window program;
} t_general;

t_window *load_window(t_window *main_window, char *title, t_keys *keys_status);
int close_x();

#endif