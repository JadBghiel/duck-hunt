/*
** EPITECH PROJECT, 2024
** my_strcmp
** File description:
** compares two strings
*/
#include "../../include/my.h"

int my_tolower(int c)
{
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

int my_strcmp(char const *s1, char const *s2)
{
    int i;
    char c1;
    char c2;

    for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        c1 = my_tolower((unsigned char) s1[i]);
        c2 = my_tolower((unsigned char) s2[i]);
        if (c1 > c2)
            return 1;
        if (c1 < c2)
            return -1;
    }
    if (s1[i] != '\0')
        return 1;
    if (s2[i] != '\0')
        return -1;
    return 0;
}
