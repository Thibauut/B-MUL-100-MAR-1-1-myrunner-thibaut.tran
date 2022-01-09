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
		src/my_func_link_list.c	\
		menu/my_menu_anim.c	\
		menu/my_menu_event.c	\
		menu/my_menu.c	\
		menu/my_init_menu.c	\
		menu/tutorial/my_tutorial.c	\
		menu/tutorial/my_tutorial_anim.c	\
		menu/my_menu_rect.c	\
		game/my_game.c	\
		game/my_init_game.c	\
		game/my_game_anim.c	\
		game/my_game_event.c	\
		game/my_game_rect.c	\
		game/my_game_rect2.c	\
		game/my_game_rect3.c	\
		game/my_game_clock.c	\
		game/my_display_game.c	\
		game/my_end.c	\
		game/my_score.c	\
		game/player/my_player_rect.c	\
		game/player/my_player_anim.c	\
		game/obstacle/my_add_obs.c	\
		game/obstacle/my_obs_anim.c	\
		game/obstacle/my_rect_obs.c	\
		game/obstacle/my_move_obs.c	\
		game/obstacle/my_put_obs.c	\
		game/collision/my_collision_1.c	\
		game/collision/my_collision_2.c	\
		game/collision/my_collision_3.c	\
		game/collision/my_collide_rect.c	\
		my_runner.c


CFLAGS = -Wno-deprecated-declarations

OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

all	:	$(NAME)	$(SRC)

$(NAME)	:	$(OBJ)
	gcc $(CFLAGS)	$(SRC)	-o	$(NAME)	-I/usr/local/include/	-L/usr/local/	-lcsfml-graphics	-lcsfml-window	-lcsfml-audio	-lcsfml-system

clean :
	rm	-f	*.o
	rm	-f	*~
	rm	-f	src/*.o
	rm	-f	game/*.o
	rm	-f	game/obstacle/*.o
	rm	-f	game/collision/*.o
	rm	-f	game/player/*.o
	rm	-f	menu/*.o
	rm	-f	menu/tutorial/*.o

fclean :
	rm	-f	$(NAME)

re :	fclean	all	clean