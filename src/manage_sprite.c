/*
** EPITECH PROJECT, 2024
** manage_sprit
** File description:
** manages the sprites
*/
#include "../include/my_hunter.h"

sfSprite *create_sprite(char *filepath)
{
    sfSprite *sprite;
    sfTexture *texture;

    sprite = sfSprite_create();
    texture = sfTexture_createFromFile(filepath, NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

void handle_bird_movement(bird_params_t *params)
{
    if (!params->is_dead) {
        move_sprite(params);
    } else {
        if (params->spawn_time >= 1.0f) {
            reset_bird(params);
        }
    }
}

void move_sprite(bird_params_t *params)
{
    sfVector2f position;

    params->pos_x += params->speed;
    if (params->pos_x >= params->window_width) {
        params->pos_x = -32;
    }
    position.x = params->pos_x;
    position.y = params->pos_y;
    sfSprite_setPosition(params->sprite, position);
}

void animate_sprite(bird_params_t *params)
{
    sfTime time = sfClock_getElapsedTime(params->clock);
    float elapsed = sfTime_asSeconds(time);
    float frame_duration = 0.1f;

    if (elapsed >= frame_duration) {
        params->rect.left += params->rect.width;
        if (params->rect.left >= params->rect.width * params->frame_count) {
            params->rect.left = 0;
        }
        sfSprite_setTextureRect(params->sprite, params->rect);
        sfClock_restart(params->clock);
    }
}

void reset_bird(bird_params_t *params)
{
    params->sprite = create_sprite("./rsrc/flappy_sprite_sheet.png");
    params->pos_x = -32;
    params->pos_y = rand() % (params->mode.height - 200);
    params->is_dead = false;
    params->spawn_time = 0.0f;
}
