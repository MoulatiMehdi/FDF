#ifndef FDF_H

#define FDF_H
#define NULL ((void *)0)



#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "keys.h"
#include "config.h"

typedef struct s_point2d
{
    double x;
    double y;
} t_point2d;

typedef struct s_point3d
{
    double x;
    double y;
    double z;
} t_point3d;

typedef struct s_graphic {
    void *mlx;
    void *window;
} t_graphic;

typedef struct s_data {
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
} t_data;



t_graphic* new_window(char *title, int width, int height); 
void new_image(t_graphic*session,t_data * data,int width,int height);
int draw_image(t_graphic* session,t_data * data,int x,int y);

double dist_2d(t_point2d* a,t_point2d* b);
double dist_3d(t_point3d* a,t_point3d* b);
void set_2d(t_point2d * p,int x,int y);
void set_3d(t_point3d * p,int x,int y,int z);
int rgba(unsigned char red,unsigned char green,unsigned char blue,unsigned char opacity);

void draw_pixel(t_data *data, int x, int y, int color);
void draw_line(t_data * data,t_point2d* a,t_point2d* b,int color);
void draw_circle(t_data * data,t_point2d *center,int raduis,int color);

void fill_circle(t_data * data,t_point2d *center,int radius,int color);
void draw_grid(t_data* data,t_point2d* origin,int width,int height);
void print_point(t_point2d *p,char * label);
//void to_isometric(t_point2d *m ,t_point3d * p,double angle);
void to_isometric(t_point2d *m ,t_point3d * p,double angle,int shift);
#endif
