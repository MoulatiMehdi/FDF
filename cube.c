#include "fdf.h"

void new_cube(t_cube * cube,t_point3d *center, int side,double angle)
{
    cube->side = side;
    cube->center = center;
    
    set_3d(&cube->points[0],center->x - side/2.0,center->y -side/2.0,center->z - side/2.0); // A
    set_3d(&cube->points[1],center->x - side/2.0,center->y - side/2.0,center->z + side/2.0); // B
    set_3d(&cube->points[2],center->x + side/2.0,center->y - side/2.0,center->z + side/2.0); // C
    set_3d(&cube->points[3],center->x + side/2.0,center->y - side/2.0,center->z - side/2.0); // D
    
    set_3d(&cube->points[4],center->x - side/2.0,center->y + side/2.0,center->z - side/2.0); // E
    set_3d(&cube->points[5],center->x - side/2.0,center->y + side/2.0,center->z + side/2.0); // F
    set_3d(&cube->points[6],center->x + side/2.0,center->y + side/2.0,center->z + side/2.0); // G
    set_3d(&cube->points[7],center->x + side/2.0,center->y + side/2.0,center->z - side/2.0); // H

    
}
