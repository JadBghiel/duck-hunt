/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** header file for my_hunter project
*/
#ifndef MY_HUNTER
    #define MY_HUNTER
    #include "my.h"
    #include "common_lib.h"

//struct:
typedef struct {
    sfSprite *sprite;
    float speed;
    float pos_x;
    float window_width;
    bool is_dead;
    float pos_y;
    int frame_count;
    float spawn_time;
    sfVideoMode mode;
    sfIntRect rect;
    sfClock *clock;
    int score;
    sfText *score_text;
    sfFont *font;
    bool is_game_over;
} bird_params_t;

//function prototype below

//manage_sprit.c:
sfSprite *create_sprite(char *filepath);
void handle_bird_movement(bird_params_t *params);
void move_sprite(bird_params_t *params);
void animate_sprite(bird_params_t *params);
void reset_bird(bird_params_t *params);


//terminate.c:
void terminate(sfRenderWindow *window, sfSprite *background, sfSprite *bird,
    bird_params_t *params);

//extra_features.c:
void display_info(void);
int convert_int_to_str(int score, char *buffer);
int score(sfRenderWindow *window, bird_params_t *params);

//manage_events.c:
int game_loop(sfRenderWindow *window, sfEvent *event, sfSprite *background,
    bird_params_t *params);
void handle_mouse_click(sfEvent *event, bird_params_t *params);
int manage_events(sfRenderWindow *window, sfEvent *event,
    bird_params_t *params);

//main.c:
bird_params_t initialize_bird_params(sfVideoMode mode);

//scale_handling.c:
#endif /* MY_HUNTER */
