##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## No description
##

all: 	 graphicals

graphicals:
		@make --no-print-directory -C ./NCurses
		@make --no-print-directory -C ./SDL
		@make --no-print-directory -C ./SFML

clean:
		@make --no-print-directory clean -C ./NCurses
		@make --no-print-directory clean -C ./SDL
		@make --no-print-directory clean -C ./SFML

fclean:	clean
		@make --no-print-directory fclean -C ./NCurses
		@make --no-print-directory fclean -C ./SDL
		@make --no-print-directory fclean -C ./SFML

re:		fclean all

.PHONY:			all clean fclean re
