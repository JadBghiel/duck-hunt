/*
** EPITECH PROJECT, 2024
** manage_events
** File description:
** manages the events
*/
#include "../include/my_hunter.h"

int game_loop(sfRenderWindow *window, sfEvent *event, sfSprite *background,
    bird_params_t *params)
{
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        if (manage_events(window, event, params)) {
            return 0;
        }
        if (!params->is_dead) {
            animate_sprite(params);
        }
        sfRenderWindow_drawSprite(window, background, NULL);
        handle_bird_movement(params);
        sfRenderWindow_drawSprite(window, params->sprite, NULL);
        score(window, params);
        sfRenderWindow_display(window);
        params->spawn_time += 0.016f;
    }
    return 0;
}

void handle_mouse_click(sfRenderWindow *window, sfEvent *event,
    bird_params_t *params)
{
    sfFloatRect bounds;
    sfVector2f mouse_world_pos;
    sfTexture *dead_texture;
    sfVector2i mouse_pixel_pos;

    if (event->mouseButton.button == sfMouseLeft) {
        mouse_pixel_pos.x = event->mouseButton.x;
        mouse_pixel_pos.y = event->mouseButton.y;
        mouse_world_pos = sfRenderWindow_mapPixelToCoords(window,
            mouse_pixel_pos, NULL);
        bounds = sfSprite_getGlobalBounds(params->sprite);
        if (sfFloatRect_contains(&bounds, mouse_world_pos.x,
            mouse_world_pos.y) && !params->is_dead) {
            params->is_dead = true;
            dead_texture = sfTexture_createFromFile("./rsrc/dead.png", NULL);
            sfSprite_setTexture(params->sprite, dead_texture, sfTrue);
            params->score += 1;
        }
    }
}

int manage_events(sfRenderWindow *window, sfEvent *event,
    bird_params_t *params)
{
    while (sfRenderWindow_pollEvent(window, event)) {
        if (event->type == sfEvtClosed) {
            sfRenderWindow_close(window);
            return 1;
        }
        if (event->type == sfEvtMouseButtonPressed) {
            handle_mouse_click(window, event, params);
        }
    }
    return 0;
}
