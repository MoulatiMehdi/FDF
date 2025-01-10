#include "fdf.h"

int close_window(t_graphic *session)
{
    mlx_destroy_window(session->mlx, session->window);
    free(session);
    exit(0);
}

int handle_keys(int keycode, t_graphic *session) {
    if (keycode == KEY_ESC ) 
        close_window(session);
    else if (keycode == KEY_L)
        mlx_clear_window(session->mlx, session->window);
    else
        printf("key : %d\n",keycode);
    return 0;
}


t_graphic * new_window(char *title, int width, int height) 
{
    t_graphic *session;

    session = malloc(sizeof(t_graphic));
    session->mlx = mlx_init();
    session->window = NULL;

    if (session->mlx == NULL)
        return NULL;

    if (height <= DEFAULT_MIN_HEIGHT)
        height = DEFAULT_HEIGHT;
    if (width <= DEFAULT_MIN_WIDTH)
        width = DEFAULT_WIDTH;

    session->window = mlx_new_window(session->mlx, width, height, title);
    mlx_key_hook(session->window, handle_keys, session);
    mlx_hook(session->window, 17, 0, close_window, session);

    return session;
}

void new_image(t_graphic*session,t_data * data,int width,int height)
{
    data->img = mlx_new_image(session->mlx, width, height);
    data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
                                   &data->line_length, &data->endian);
}

int draw_image(t_graphic* session,t_data * data,int x,int y)
{
    return mlx_put_image_to_window(session->mlx, session->window, data->img, x, y);
}
