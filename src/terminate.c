/*
** EPITECH PROJECT, 2024
** terminate
** File description:
** terminate the program
*/
#include "../include/my_hunter.h"

static void destroy_texture(const sfTexture *texture)
{
    if (texture) {
        sfTexture_destroy((sfTexture *)texture);
    }
}

static void destroy_sprite(sfSprite *sprite)
{
    const sfTexture *texture;

    if (sprite) {
        texture = sfSprite_getTexture(sprite);
        destroy_texture(texture);
        sfSprite_destroy(sprite);
    }
}

static void destroy_bird_params(bird_params_t *params)
{
    if (params->score_text) {
        sfText_destroy(params->score_text);
    }
    if (params->font) {
        sfFont_destroy(params->font);
    }
}

static void destroy_window(sfRenderWindow *window)
{
    if (window) {
        sfRenderWindow_close(window);
        sfRenderWindow_destroy(window);
    }
}

static void destroy_soundtrack(sfMusic *soundtrack)
{
    if (soundtrack) {
        sfMusic_stop(soundtrack);
        sfMusic_destroy(soundtrack);
    }
}

void terminate(sfRenderWindow *window, sfSprite *background, sfSprite *bird,
    bird_params_t *params)
{
    destroy_sprite(background);
    destroy_sprite(bird);
    destroy_bird_params(params);
    destroy_window(window);
    destroy_soundtrack(params->soundtrack);
}
