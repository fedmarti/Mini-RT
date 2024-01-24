#ifndef MOUSE_H
#define MOUSE_H


# define CLK_LEFT 1
# define CLK_RIGHT 2
# define CLK_MIDDLE 3
# define SCROLL_UP 4
# define SCROLL_DOWN 5

enum MouseEvents
{
    pressed_left = 1,
    pressed_right = 2,
    pressed_middle = 3,
    scroll_up = 4,
    scroll_down = 5
};

typedef struct s_mouse
{
	float mouse_x;
	float mouse_y;
	enum MouseEvents pressed;
	bool left_is_on_hold;
	bool right_is_on_hold;
} t_mouse;

int on_click_event(int button, int x, int y, void *parameter);

#endif