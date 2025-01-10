#ifndef WINDOW_H
#define WINDOW_H

#define NULL ((void *)0)

#define DEFAULT_HEIGHT 1080
#define DEFAULT_MIN_HEIGHT 0
#define DEFAULT_MAX_HEIGHT 100

#define DEFAULT_WIDTH 1920
#define DEFAULT_MIN_WIDTH 0
#define DEFAULT_MAX_WIDTH 100

typedef struct s_window {
    void *mlx;
    void *window;
} t_window;

#include "mlx.h"


t_window new_window(char *title, int height, int width); 
#endif 
