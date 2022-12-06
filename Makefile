##
## EPITECH PROJECT, 2022
## bsq
## File description:
## Makefile
##

SRC				=	source/main_file.c\
					source/open_sokoban.c\
					source/sokoban_game.c\
					source/check_for_errors.c\
					source/manage_map.c\
					source/manage_events.c\
					source/pos.c\
					source/lost.c

OBJ				=	$(SRC:.c=.o)

CPPFLAGS		=	-Wall -Wextra -I./include/ -lncurses

MYH				=	include/my.h

DIR				=	-L./lib/ -lmy

LIBNAME			=	libmy.a

NAME			=	my_sokoban

all: compil

compil : $(OBJ)
	$(MAKE) -C ./lib/my
	gcc -o $(NAME) $(OBJ) $(DIR) $(LIB) $(CPPFLAGS)

debug:	CPPFLAGS += -g3 -Wall -Wextra
debug:	re

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C ./lib/my

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./lib/my

re: fclean all

.PHONY: all makelib clean fclean re
