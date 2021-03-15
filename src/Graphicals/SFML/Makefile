##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## No description
##

SRC_SFML = SFML.cpp

OBJ_SFML = $(SRC_SFML:.cpp=.o)

CCX =	g++

RM =	rm -f

FLAGS_SFML = -lsfml-graphics -lsfml-window -lsfml-system

SFML_LIB_GRAPHICAL = ../../../lib/lib_arcade_sfml.so

OUTPUT = -o

CXXFLAGS = -fPIC -shared -rdynamic

CPPFLAGS = -I../../

all: 	 graphicals

graphicals: $(OBJ_SFML)
			$(CCX) $(OUTPUT) $(SFML_LIB_GRAPHICAL) $(OBJ_SFML) $(FLAGS_SFML) $(CXXFLAGS)

clean:
		$(RM) $(OBJ_SFML)

fclean:	clean
		$(RM) $(SFML_LIB_GRAPHICAL)

re:		fclean all

.PHONY:	all clean fclean re
