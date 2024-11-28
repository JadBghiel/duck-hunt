/*
** EPITECH PROJECT, 2024
** main
** File description:
** main file for setting_up project
*/
#include "../include/my_hunter.h"

bird_params_t initialize_bird_params(sfVideoMode mode)
{
    bird_params_t params = {0};

    params.sprite = create_sprite("./rsrc/flappy_sprite_sheet.png");
    params.speed = 7.0f;
    params.pos_x = -32;
    params.pos_y = 300;
    params.window_width = mode.width;
    params.is_dead = false;
    params.frame_count = 3;
    params.spawn_time = 0.0f;
    params.mode = mode;
    params.rect = (sfIntRect){0, 0, 174, 122};
    params.clock = sfClock_create();
    params.score = 0;
    params.font = sfFont_createFromFile("./rsrc/font_joystick.otf");
    params.score_text = sfText_create();
    sfText_setFont(params.score_text, params.font);
    sfText_setCharacterSize(params.score_text, 75);
    sfText_setFillColor(params.score_text, sfBlack);
    return params;
}

static int handle_help_argument(int argc, char **argv)
{
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
        display_info();
        return 1;
    }
    return 0;
}

static int setup_environment(sfRenderWindow **window, sfSprite **background,
    bird_params_t *bird_params)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfUint32 style = sfClose | sfResize;

    *window = sfRenderWindow_create(mode, "my hunter", style, NULL);
    *background = create_sprite("./rsrc/mario_background.png");
    *bird_params = initialize_bird_params(mode);
    if (!*window || !*background || !bird_params->sprite ||
        !bird_params->score_text || !bird_params->font) {
        terminate(*window, *background, bird_params->sprite, bird_params);
        return 84;
    }
    return 0;
}

static int handle_game(sfRenderWindow *window, sfSprite *background,
    bird_params_t *bird_params)
{
    sfEvent event = {0};

    srand(time(NULL));
    sfRenderWindow_setFramerateLimit(window, 60);
    if (game_loop(window, &event, background, bird_params) != 0) {
        terminate(window, background, bird_params->sprite, bird_params);
        return 84;
    }
    terminate(window, background, bird_params->sprite, bird_params);
    return 0;
}

int main(int argc, char **argv)
{
    sfRenderWindow *window = NULL;
    sfSprite *background = NULL;
    bird_params_t bird_params;

    if (handle_help_argument(argc, argv)) {
        return 0;
    }
    if (setup_environment(&window, &background, &bird_params) == 84) {
        return 84;
    }
    return handle_game(window, background, &bird_params);
}
