#ifndef KEY_H

#define KEY_H

typedef enum e_keyboard_key {
    KEY_ESC = 65307 ,
    KEY_L = 108,
} t_keyboard_key;


typedef enum  e_event_key {
    ON_KEYDOWN = 2,
    ON_KEYUP = 3,
    ON_MOUSEDOWN = 4,
    ON_MOUSEUP = 5,
    ON_MOUSEMOVE = 6,
    ON_EXPOSE = 12,
    ON_DESTROY = 17
} t_event_key ;

#endif
