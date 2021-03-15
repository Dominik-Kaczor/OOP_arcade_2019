##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## No description
##

SRC_SDL = SDL.cpp

OBJ_SDL = $(SRC_SDL:.cpp=.o)

CCX =	g++

RM =	rm -f

FLAGS_SDL = -lSDL2 -lSDL2_ttf

SDL_LIB_GRAPHICAL = ../../../lib/lib_arcade_SDL2.so

OUTPUT = -o

CXXFLAGS = -fPIC -shared -rdynamic

CPPFLAGS = -I../../

all: 	 graphicals

graphicals: $(OBJ_SDL)
			$(CCX) $(OUTPUT) $(SDL_LIB_GRAPHICAL) $(OBJ_SDL) $(FLAGS_SDL) $(CXXFLAGS)

clean:
		$(RM) $(OBJ_SDL)

fclean:	clean
		$(RM) $(SDL_LIB_GRAPHICAL)

re:		fclean all

.PHONY:	all clean fclean re
