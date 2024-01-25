#ifndef MOUSE_H
#define MOUSE_H

# define CLK_LEFT 1

typedef struct s_mouse
{
	float mouse_x;
	float mouse_y;
	bool pressed;
} t_mouse;

int on_click_event(int button, int x, int y, void *parameter);

#endif