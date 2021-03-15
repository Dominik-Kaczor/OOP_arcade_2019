##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## No description
##

SRC_NCurses = NCurses.cpp

OBJ_NCurses = $(SRC_NCurses:.cpp=.o)

CCX =	g++

RM =	rm -f

FLAGS_NCurses = -lncurses

NCurses_LIB_GRAPHICAL = ../../../lib/lib_arcade_ncurses.so

OUTPUT = -o

CXXFLAGS = -fPIC -shared -rdynamic

CPPFLAGS = -I../../

all: 	 graphicals

graphicals: $(OBJ_NCurses)
			$(CCX) $(OUTPUT) $(NCurses_LIB_GRAPHICAL) $(OBJ_NCurses) $(FLAGS_NCurses) $(CXXFLAGS)

clean:
		$(RM) $(OBJ_NCurses)

fclean:	clean
		$(RM) $(NCurses_LIB_GRAPHICAL)

re:		fclean all

.PHONY:	all clean fclean re
