#include "color.h"

int rgba(unsigned char red,unsigned char green,unsigned char blue,unsigned char opacity)
{
    int color;

    color = 0;
    color |= opacity;
    color <<= 8;
    color |= red;
    color <<= 8;
    color |= green;
    color <<= 8;
    color |= blue;

    return color;
}
