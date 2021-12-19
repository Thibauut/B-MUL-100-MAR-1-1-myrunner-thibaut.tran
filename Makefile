##
## EPITECH PROJECT, 2021
## B-CPE-110-MAR-1-1-BSQ-thibaut.tran
## File description:
## Makefile
##

SRC	=	src/my_func.c	\
		src/my_func_2.c	\
		src/load_my_map.c	\
		src/my_h.c	\
		src/my_create.c	\
		src/check_map.c	\
		menu/my_menu_anim.c	\
		menu/my_menu_event.c	\
		menu/my_menu.c	\
		game/my_game.c	\
		game/my_game_anim.c	\
		game/my_game_event.c	\
		game/my_game_rect.c	\
		game/my_game_clock.c	\
		my_runner.c


CFLAGS = -Wno-deprecated-declarations

OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

all	:	$(NAME)	$(SRC)

$(NAME)	:	$(OBJ)
	gcc $(CFLAGS)	$(SRC)	-o	$(NAME)	-I/usr/local/include/	-L/usr/local/	-lcsfml-graphics	-lcsfml-window	-lcsfml-audio	-lcsfml-system
	# a enlever :
	rm	-f	src/*.o
	rm	-f	game/*.o
	rm	-f	menu/*.o
	rm	-f	*.o

clean :
	rm	-f	*.o
	rm	-f	*~
	rm	-f	src/*.o

fclean :	clean
	rm	-f	$(NAME)

re :	fclean	all