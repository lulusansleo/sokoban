/*
** EPITECH PROJECT, 2022
** strncpy
** File description:
** only file
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int i = 0; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[n] = '\0';
    return dest;
}
