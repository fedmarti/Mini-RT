#include "minirt.h"

void shift_left_on(void *general)
{
	t_general g = (*(t_general *)general);
	t_sphere *sphere;
	
	if(g.selected_type == Sphere)
		sphere = (t_sphere *)g.selected;
	sphere->diameter-=20;
	printf("SHift left!\n");
}
void shift_up_on(void *general)
{
	(void)general;
	static int i=0;
	printf("SHift up! %d\n", i++);
}
void shift_right_on(void *general)
{
	t_general g = (*(t_general *)general);
	t_sphere *sphere;
	
	if(g.selected_type == Sphere)
		sphere = (t_sphere *)g.selected;
	sphere->diameter+=20;
	printf("SHift left!\n");
}
void shift_down_on(void *general)
{
	(void)general;
	printf("SHift down!\n");
}