#include "point.h"


void set_point(t_point * p,int x,int y)
{
    p->x = x;
    p->y = y;
}

double distance(t_point* a,t_point* b)
{
    int dx;
    int dy;

    dx = a->x - b->x;
    dy = a->y - b->y;

    return sqrt(dx*dx + dy*dy);
}
