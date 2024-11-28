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

void handle_mouse_click(sfEvent *event, bird_params_t *params)
{
    sfFloatRect bounds;
    sfTexture *dead_texture;

    if (event->mouseButton.button == sfMouseLeft) {
        bounds = sfSprite_getGlobalBounds(params->sprite);
        if (sfFloatRect_contains(&bounds, event->mouseButton.x,
            event->mouseButton.y) && !params->is_dead) {
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
            handle_mouse_click(event, params);
        }
    }
    return 0;
}
