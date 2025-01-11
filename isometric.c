#include "fdf.h"
#include <math.h>



#define M_SQRT1_6 0.4082482904639

double to_rad(double degree)
{
    return degree * (M_PI / 180.0);

}


void to_isometric(t_point2d *m ,t_point3d * p,t_point2d *shift)
{
    double angle = 30;
    m->x = shift->x + (p->x - p->y) * cos(to_rad(angle)); 
    m->y = shift->y + (p->x + p->y) * sin(to_rad(angle))  - p->z; 
}

void rotate_z(t_point2d *from,t_point2d * to,double angle,t_point2d *shift)
{
    double x = from->x;
    double y = from->y;
    to->x =shift->x + x * cos(to_rad(angle)) - y * sin(to_rad(angle)); 
    to->y =shift->y + x * sin(to_rad(angle)) + y * cos(to_rad(angle)); 
}
