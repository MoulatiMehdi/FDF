#include "color.h"
#include "window.h"
#include "point.h"

#include <mlx.h>
#include <math.h>
#include <stdio.h>


typedef struct s_data {
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
} t_data;

void draw_pixel(t_data *data, int x, int y, int color) {
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void draw_line(t_data * data,t_point* a,t_point* b,int color)
{
    double dx;
    double dy;
    int pixels;
    double x0;
    double y0;

    pixels = distance(a,b);
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

void draw_circle(t_data * data,t_point *center,int raduis,int color)
{
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

int is_incircle(t_point*center,int radius,t_point *p)
{
    if(radius == 0) 
        return 0;
    return (p-> x - center->x) * (p->x - center->x) + (p->y - center->y) + (p-> y - center->y) == radius * radius;
}

void fill_circle(t_data * data,t_point *center,int radius,int color)
{
    double dr;
    double deg;
    t_point p0;

    if(radius == 0)
        return NULL;

    p0.y = center->y - radius;
    while(p0.y <= center->x + radius)
    {
        while(is_incircle(center,radius, &p0))
        {
            
        }
        p0.y++;
    }

}

int main(void) {

    t_data data;
    t_window win1;

    t_point a;
    t_point b;
    t_point c;

    set_point(&a,135,135);
    set_point(&b,100,100);
    set_point(&c,150,100);


    win1 = new_window("Test", 1920, 1080);
    data.img = mlx_new_image(win1.mlx, 1920, 1080);
    data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
                                  &data.line_length, &data.endian);

    //draw_line(&data, &a, &b, rgba(0,255,0,0));
    //draw_line(&data, &c, &b, rgba(255,0,0,0));
    fill_circle(&data,&b,50,rgba(255,255,0,0));
    mlx_put_image_to_window(win1.mlx, win1.window, data.img, 0, 0);
    mlx_loop(win1.mlx);
}
