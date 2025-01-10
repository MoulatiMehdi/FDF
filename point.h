#ifndef POINT_H
#define POINT_H

#include <math.h>

typedef struct s_point
{
    int x;
    int y;
} t_point;


double distance(t_point* a,t_point* b);
void set_point(t_point * p,int x,int y);


#endif
