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
    int sokoban(char *buffer);
    int check_map(char *buffer);
    pos_t change_pos_if(pos_t player_pos, int i, int j, char **map);
    pos_t get_pos(char **map);
    pos_t get_vect(int x, int y);
    int push_block(pos_t *block_pos, char **map, pos_t move);
    int won(char **map, char **cpy);
    void move_player(pos_t *player_pos, char **map, pos_t move, char **copy);

#endif /* !sokoban_h */
