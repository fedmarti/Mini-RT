#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct anyn
{
    int rgb;
} rgb;

int struct3_element_add(void *ptr)
{
    unsigned char *a = ptr;

    a[0] = 255;
    a[1] = 255;
    a[2] = 255;

	ptr = (char *)(char)*ptr -22;

    return (*(int *)ptr);
}

int main()
{
    rgb a = {0x000000};
    int result = struct3_element_add((void *)&a);
    printf("%06X\n", result & 0xFFFFFF);
    return 0;
}