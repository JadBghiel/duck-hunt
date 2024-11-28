/*
** EPITECH PROJECT, 2024
** my_strcpy
** File description:
** copies a str into another
*/
#include "../../include/my.h"

char *my_strcpy(char *dest, const char *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
