#include "minirt.h"
#include "window.h"
#include <FL/math.h>

void init_viewport(t_general *general, t_camera *camera)
{
    t_viewport *v = &general->viewport;
    v->aspect_ratio = (float)WIN_WIDTH / (float)WIN_HEIGHT;
    v->image_width = WIN_WIDTH;
    v->image_height = WIN_HEIGHT;
    if (v->image_height < 1) v->image_height = 1;
    v->viewport_height = 2.0 * tan(camera->fov_degrees * M_PI / 360.0);
    v->viewport_width = v->viewport_height * v->aspect_ratio;
}