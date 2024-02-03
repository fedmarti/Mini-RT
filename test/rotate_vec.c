#include "geometry_3d.h"
#include "cglm.h"
#include <stdlib.h>
#include <string.h>

#include <stdio.h>

void	swap(float arr[][3], int index1, int index2)
{
	float	temp[3];
	
	memcpy(temp, arr[index1], sizeof(temp));
	memcpy(arr[index1], arr[index2], sizeof(temp));
	memcpy(arr[index2], temp, sizeof(temp));
}

int main(void)
{
	t_vec3	vector = {0, 0, 1};
	float	glm_result[3] = {vector.x, vector.y, vector.z};
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
	{
		//glm test
		float	axis[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
		{
		swap(axis, 1, 2);
		t_radians temp = rot_y;
		rot_y = rot_z;
		rot_z = temp;
		}
		for (size_t i = 0; i < sizeof(axis) / sizeof(*axis); i++)
			glm_vec3_rotate(glm_result, rot_x, axis[i]);
		printf("vector: [%f, %f, %f]\n", glm_result[0], glm_result[1], glm_result[2]);
	}


	
}