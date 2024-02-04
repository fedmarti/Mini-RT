#ifndef VIEWPORT_H
#define VIEWPORT_H

#include "minirt.h"
#include "window.h"
/*viewport_u rappresenta un vettore che punta nella direzione della larghezza di questa 
finestra (viewport). Immagina di stare davanti al tuo schermo: viewport_u va da sinistra 
a destra lungo la larghezza dello schermo.

viewport_v rappresenta un vettore che punta nella direzione dell'altezza del viewport, 
ma con una peculiarità: va dall'alto verso il basso (perché ha un segno negativo sulla componente dell'altezza).
Quindi, se sei davanti al tuo schermo, 
viewport_v va dal bordo superiore dello schermo verso il basso.*/

typedef struct s_viewport
{
	double aspect_ratio;
	double image_width;
	double image_height;
	double focal_len;

	double viewport_height;
	double viewport_width;

	t_vec3 viewport_u;
	t_vec3 viewport_v;
	
	double pixel_u;
	double pixel_v;

	t_vec3 viewport_starting_point;
	t_vec3 center_of_0_index_pixel;


} t_viewport;

#endif