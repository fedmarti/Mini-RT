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
	t_vec3 actual_raydir;
	int  x;
	int  y;
	int		image_width;
	int 	image_height;
	float 	aspect_ratio;
	float 	viewport_height;
	float 	viewport_width;
} t_viewport;

#endif