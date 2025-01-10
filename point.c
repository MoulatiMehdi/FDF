#include "fdf.h"
#include <stdio.h>


void set_2d(t_point2d * p,int x,int y)
{
    p->x = x ;
    p->y = y ;
}

void set_3d(t_point3d * p,int x,int y,int z)
{
    p->x = x; 
    p->y = y; 
    p->z = z;
}

double dist_2d(t_point2d* a,t_point2d* b)
{
    double dx;
    double dy;

    dx = a->x - b->x;
    dy = a->y - b->y;

    return sqrt(dx*dx + dy*dy);
}

double dist_3d(t_point3d* a,t_point3d* b)
{
    double dx;
    double dy;
    double dz;

    dx = a->x - b->x;
    dy = a->y - b->y;
    dz = a->z - b->z;

    return sqrt(dx*dx + dy*dy + dz*dz);
}


void print_point(t_point2d *p,char * label)
{
    printf("%s : (%0.2f,%0.2f)\n",label,p->x,p->y);

}
