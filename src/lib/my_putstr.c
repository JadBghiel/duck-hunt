/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** displays the chars of a string one by one
*/
#include "../../include/my.h"

int my_putstr(char const *str)
{
    while (*str != '\0') {
        my_putchar(*str);
        str++;
    }
    return 0;
}
