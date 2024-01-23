#ifndef WINDOW_H
#define WINDOW_H

//KEYPRESS MACRO
# define ESC 65307

typedef struct s_window
{
	void	*init_ptr;
	void	*window;
} t_window;

t_window *load_window(t_window *main_window);

#endif