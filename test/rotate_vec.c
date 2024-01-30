#include "geometry_3d.h"
#include ""

#include <stdio.h>

int main(void)
{
	t_vec3	vector = {0, 0, 1};
	t_radians	rot_x, rot_y, rot_z;

	printf("vector: [%f, %f, %f]\n", vector.x, vector.y, vector.z);
	printf("x angle:\n");
	scanf("%f", &rot_x);
	printf("y angle:\n");
	scanf("%f", &rot_y);
	printf("z angle:\n");
	scanf("%f", &rot_z);
	vector = vec3_rotate(vector, rot_x, rot_y, rot_z);
	printf("vector: [%f, %f, %f]\n", vector.x, vector.y, vector.z);
}