#include "window.h"
#include "key.h"
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

int close_window(int keycode, t_window *window) {
    printf("%d\n",keycode);
    if (keycode == 65307) { 
        mlx_destroy_window(window->mlx, window->window);
        exit(0);
    }
    return 0;
}


t_window new_window(char *title, int height, int width) 
{
    t_window win;

    win.mlx = mlx_init();
    win.window = NULL;
    
    if (win.mlx == NULL)
        return win;
    
    if (height <= DEFAULT_MIN_HEIGHT)
        height = DEFAULT_HEIGHT;
    if (width <= DEFAULT_MIN_WIDTH)
        width = DEFAULT_WIDTH;

    win.window = mlx_new_window(win.mlx, width, height, title);
    mlx_hook(win.window, ON_KEYDOWN, 1L << 0, close_window, (void *)&win);

    return win;
}
