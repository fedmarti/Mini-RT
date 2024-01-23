#ifndef WINDOW_H
#define WINDOW_H

//KEYPRESS MACRO
# define ESC 65307
# define LEFT_CLK 1
# define RIGHT_CLK 2

typedef struct s_window
{
	void	*init_ptr;
	void	*window;
	float	aspectratio;
} t_window;

t_window *load_window(t_window *main_window);

#endif