#include "fdf.h"
#include <mlx.h>

#define HEIGHT   1000
#define WIDTH    2000
int main(void) {

    t_data data;
    t_graphic * session;

//    t_point2d a;
 //   t_point2d b;
 //   t_point2d c;

    t_point3d cube[8];
    t_point2d iso_cube[8];

    session = new_window("Test", WIDTH + 100,HEIGHT + 100);
    if(session == NULL || session->window == NULL)
    {
        free(session);
        return 1;
    }
    
    new_image(session,&data,WIDTH,HEIGHT);
    
    //set_2d(&a,3,3);
    //set_2d(&b,WIDTH/2,HEIGHT/2);
    //set_2d(&c,150,100);
    int side = 100;
    
    set_3d(&cube[0],0,0,0); // A
    set_3d(&cube[1],0,0,side); // B
    set_3d(&cube[2],side,side,0); // C
    set_3d(&cube[3],side,0,0); // D
    
    set_3d(&cube[4],0,side,0); // E
    set_3d(&cube[5],0,side,side); // F
    set_3d(&cube[6],side,side,side); // G
    set_3d(&cube[7],side,side,0); // H

    for(int i = 0; i < 8 ; i ++)
    {
        to_isometric(&iso_cube[i], &cube[i], 30,2*side);
        fill_circle(&data, &iso_cube[i], 5, rgba(255,255,0,0));
    }
    t_point2d *A = &iso_cube[0];
    t_point2d *B = &iso_cube[1];
    t_point2d *C = &iso_cube[2];
    t_point2d *D = &iso_cube[3];
    t_point2d *E = &iso_cube[4];
    t_point2d *F = &iso_cube[5];
    t_point2d *G = &iso_cube[6];
    t_point2d *H = &iso_cube[7];
    

    draw_line(&data, H, D, rgba(255,255,255,0));
    draw_line(&data, H, E, rgba(255,255,255,0));
    draw_line(&data, H, G, rgba(255,255,255,0));
    
    draw_line(&data, F, B, rgba(255,255,255,0));
    draw_line(&data, F, G, rgba(255,255,255,0));
    draw_line(&data, F, E, rgba(255,255,255,0));
    
    draw_line(&data, C, G, rgba(255,255,255,0));
    draw_line(&data, C, B, rgba(255,255,255,0));
    draw_line(&data, C, D, rgba(255,255,255,0));
   
    // coordinations 
    draw_line(&data, A, D, rgba(255,0,0,0));
    draw_line(&data, A, E, rgba(0,255,0,0));
    draw_line(&data, A, B, rgba(0,0,255,0));
    //fill_circle(&data,&b,50,rgba(255,255,0,0));
    //draw_grid(&data,&b,WIDTH,HEIGHT);
    
    draw_image(session,&data,0,0);
    mlx_loop(session->mlx);
}
