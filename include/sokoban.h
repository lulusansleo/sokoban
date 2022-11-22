/*
** EPITECH PROJECT, 2022
** my sokoban
** File description:
** -h
*/

#ifndef sokoban_h
    #define sokoban_h

    #include <ncurses.h>
    #include <fcntl.h>
    #include <sys/stat.h>

    typedef struct pos {
        short x;
        short y;
    } pos_t;

    char **buffer_to_map(char *buffer);
    void free_map(char **map);
    int open_sokoban(char const *filepath);
    void sokoban(char *buffer);
    int check_map(char *buffer);

#endif /* !sokoban_h */
