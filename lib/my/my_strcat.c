/*
** EPITECH PROJECT, 2022
** strcat
** File description:
** only file
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int a = my_strlen(dest);
    int i;

    for (i = 0; src[i] != '\0'; i++)
        dest[a + i] = src[i];
    dest[a + i] = '\0';
    return dest;
}
