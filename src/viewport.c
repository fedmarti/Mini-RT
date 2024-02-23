#include "minirt.h"
#include "window.h"
#include <FL/math.h>


void new_coordinate_viewport(t_viewport *v, t_screen coord)
{
	v->viewport_starting_point =
	vec3_add(v->viewport_starting_point, 
	(t_vec3){(coord.x * v->pixel_u), (coord.y * v->pixel_v), 0});
}

void init_viewport(t_general *general, t_camera *camera)
{
    t_viewport *v = &general->viewport;
    v->aspect_ratio = (float)WIN_WIDTH / (float)WIN_HEIGHT;
    v->image_width = WIN_WIDTH;
    v->image_height = WIN_HEIGHT;
    v->focal_len = 1.0;
    if (v->image_height < 1) v->image_height = 1;
    v->viewport_height = 2.0 * tan(camera->fov_degrees * M_PI / 360.0);
    v->viewport_width = v->viewport_height * v->aspect_ratio;
    v->viewport_u.x = v->viewport_width;
    v->viewport_v.y = v->viewport_height;
    v->pixel_u = v->viewport_u.x / v->image_width;
    v->pixel_v = v->viewport_v.y / v->image_height;
    v->viewport_starting_point = vec3_substract(vec3_substract((t_vec3){camera->x, camera->y, camera->z}, (t_vec3){0, 0, v->focal_len}), (t_vec3){v->viewport_u.x / 2, v->viewport_v.y / 2, 0});
    v->center_of_0_index_pixel = vec3_add(v->viewport_starting_point, (t_vec3){v->pixel_u / 2, v->pixel_v / 2, 0});
}