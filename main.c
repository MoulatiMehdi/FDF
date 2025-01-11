#include "fdf.h"
#include <mlx.h>
#include <string.h>

#define HEIGHT   1000
#define WIDTH    2000



typedef struct 
{
    t_graphic * session;
    t_data * data;
    t_point2d *cube;
} t_frame;

void draw_cube(t_data * data,t_point2d *cube)
{
    t_point2d *A = &cube[0];
    t_point2d *B = &cube[1];
    t_point2d *C = &cube[2];
    t_point2d *D = &cube[3];
    t_point2d *E = &cube[4];
    t_point2d *F = &cube[5];
    t_point2d *G = &cube[6];
    t_point2d *H = &cube[7];

    draw_line(data, H, D, rgba(255,255,255,0));
    draw_line(data, H, E, rgba(255,255,255,0));
    draw_line(data, H, G, rgba(255,255,255,0));
    
    draw_line(data, F, B, rgba(255,255,255,0));
    draw_line(data, F, G, rgba(255,255,255,0));
    draw_line(data, F, E, rgba(255,255,255,0));
    
    draw_line(data, C, G, rgba(255,255,255,0));
    draw_line(data, C, B, rgba(255,255,255,0));
    draw_line(data, C, D, rgba(255,255,255,0));
   
    // coordinations 
    draw_line(data, A, D, rgba(255,0,0,0));
    draw_line(data, A, E, rgba(0,255,0,0));
    draw_line(data, A, B, rgba(0,0,255,0));
}

int render_next_frame(t_frame * frame)
{

    static double degree = 0;
    
    memset(frame->data->addr,0 ,HEIGHT * frame->data->line_length);
    t_point2d rot_cube[8];
    t_point2d rot_shift;

    set_2d(&rot_shift, 500, 500);
    //fill_circle(frame->data, &rot_shift, 100, rgba(255,0,0,0));
    char label[] ="A"; 
    for(int i = 0; i < 8 ; i ++)
    {
        rotate_z(&frame->cube[i],&rot_cube[i],degree,&rot_shift);
        fill_circle(frame->data, &rot_cube[i], 5, rgba(255,255,0,0));
        label[0]+= 1;
        print_point(&rot_cube[i],label);
    }

    draw_cube(frame->data,rot_cube);    
    draw_image(frame->session,frame->data,0,0);
    degree = (degree + 0.05);
    printf("degree : %0.2f\n",degree);
    return 0;
}


int main(void) {

    t_data data;
    t_graphic * session;

    t_point3d o;

    set_3d(&o, 0,0,0);
    t_cube cube;
    session = new_window("Test", WIDTH + 100,HEIGHT + 100);
    if(session == NULL || session->window == NULL)
    {
        free(session);
        return 1;
    }
    new_image(session,&data,WIDTH,HEIGHT);
   
    new_cube(&cube,&o,100,45);
    t_point2d iso_cube[8];
    t_point2d shift;

    
    set_2d(&shift, 100, 100);

    for(int i = 0; i < 8 ; i ++)
    {
        to_isometric(&iso_cube[i],&cube.points[i],&shift);
        fill_circle(&data, &iso_cube[i], 5, rgba(255,255,0,0));
    }

    draw_cube(&data,iso_cube);

    draw_image(session,&data,0,0);
    //mlx_loop_hook(session->mlx, render_next_frame, &frame);
    mlx_loop(session->mlx);
}
