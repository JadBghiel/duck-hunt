/*
** EPITECH PROJECT, 2024
** terminate
** File description:
** terminate the program
*/
#include "../include/my_hunter.h"

void display_info(void)
{
    my_putstr("My hunter is a project based on the Duck Hunt video game !\n");
    my_putstr("This version is a crossover between Flappy Bird and Mario\n");
    my_putstr("Shoot the birds by clicking on them\n");
    my_putstr("The goal is to shoot as many birds as possible GOOD LUCK :)\n");
}

int convert_int_to_str(int score, char *buffer)
{
    int i = 0;
    char temp[10];
    int j = 0;

    if (score == 0) {
        buffer[i] = '0';
        i++;
    } else {
        while (score > 0) {
            temp[j] = (score % 10) + '0';
            j++;
            score /= 10;
        }
        for (int k = j - 1; k >= 0; k--) {
            buffer[i] = temp[k];
            i++;
        }
    }
    buffer[i] = '\0';
    return i;
}

int score(sfRenderWindow *window, bird_params_t *params)
{
    char *buffer = malloc(10 * sizeof(char));

    if (!buffer) {
        return 84;
    }
    my_strcpy(buffer, "Score : ");
    convert_int_to_str(params->score, buffer + 8);
    sfText_setString(params->score_text, buffer);
    sfRenderWindow_drawText(window, params->score_text, NULL);
    free(buffer);
    return 0;
}

sfMusic *init_soundtrack(const char *file_path)
{
    sfMusic *music = sfMusic_createFromFile(file_path);

    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
    return music;
}
