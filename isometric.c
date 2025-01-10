#include "fdf.h"
#include <math.h>

#define M_SQRT1_6 0.4082482904639

double to_rad(double degree)
{
    return degree * (M_PI / 180.0);

}


void to_isometric(t_point2d *m ,t_point3d * p,double angle,int shift)
{
    m->x = shift + p->x * cos(to_rad(angle)) + p->y * cos(to_rad(angle + 120)) + p->z * cos(to_rad(angle - 120));
    m->y = shift + p->x * sin(to_rad(angle)) + p->y * sin(to_rad(angle + 120)) + p->z * sin(to_rad(angle - 120));
}
