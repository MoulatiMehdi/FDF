#include "fdf.h"


void draw_pixel(t_data *data, int x, int y, int color) { char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void draw_line(t_data * data,t_point2d* a,t_point2d* b,int color) {
    double dx;
    double dy;
    double pixels;
    double x0;
    double y0;

    pixels = dist_2d(a,b);
    if(pixels == 0)
        return ;
    dx = a->x - b->x;
    dy = a->y - b->y;
    dx /= pixels;
    dy /= pixels;

    x0 = b->x; 
    y0 = b->y; 

    while(pixels > 0)
    {
        draw_pixel(data, x0, y0, color);
        x0 += dx;
        y0 += dy;
        pixels--;
    }
}

void draw_circle(t_data * data,t_point2d *center,int raduis,int color) {
    double dr;
    double deg;
    
    int x0;
    int y0;

    if(raduis == 0)
        return ;
    dr = 1/(double)raduis;
    deg = 0;
    while(deg < M_PI*2)
    {
        x0 = center->x  + raduis * cos(deg); 
        y0 = center->y  + raduis * sin(deg);
        draw_pixel(data, x0, y0, color);
        deg += dr;
    }
}

void fill_circle(t_data * data,t_point2d *center,int radius,int color) {
    t_point2d p[2];
    double y;
    double x;

    if(radius == 0)
        return ;
    y = center->y - radius;
    while(y <= center->y + radius)
    {
        x = sqrt(radius * radius - (center->y - y)*(center->y - y));
        set_2d(&p[0],center->x + x,y);
        set_2d(&p[1],center->x - x,y);
        draw_line(data, &p[0], &p[1], color);
        y++;
    }
}

void draw_grid(t_data* data,t_point2d* origin,int width,int height)
{
    t_point2d p[2];
    int step = 50;

    
    set_2d(&p[0],origin->x - width/2.0,origin->y - height /2.0);
    set_2d(&p[1],origin->x + width/2.0,origin->y - height /2.0);
    while(p[0].y - origin->y <= height/2.0)
    {
        print_point(&p[0],"a");
        print_point(&p[1],"b");
        draw_line(data, &p[0], &p[1], rgba(255, 0, 0,0));
        p[0].y +=step;
        p[1].y +=step;
    }
    
    set_2d(&p[0],origin->x - width/2.0,origin->y - height /2.0);
    set_2d(&p[1],origin->x - width/2.0,origin->y + height /2.0);
    while(p[0].x - origin->x <= width/2.0)
    {
        print_point(&p[0],"a");
        print_point(&p[1],"b");
        draw_line(data, &p[0], &p[1], rgba(255, 0, 0,0));
        p[0].x +=step;
        p[1].x +=step;
    }
}
