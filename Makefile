##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## No description
##

SRC_CORE	= 	src/Main.cpp \
				src/Arcade.cpp \
				src/Core/Core.cpp \
				src/Core/Arguments.cpp \
				src/Core/Component/File.cpp \
				src/Core/Component/Folder.cpp \
				src/Core/Component/DLLoader.cpp \
				src/Core/Component/Clock.cpp \
				src/Core/Component/Score.cpp \
				src/Core/Component/Timer.cpp \
				src/Core/Component/Mouse.cpp

SRC_CORE_TESTS =	tests/tests_01.cpp \
					src/Core/Core.cpp \
					src/Core/Arguments.cpp \
					src/Core/Component/File.cpp \
					src/Core/Component/Folder.cpp \
					src/Core/Component/DLLoader.cpp \
					src/Core/Component/Clock.cpp \
					src/Core/Component/Score.cpp \
					src/Core/Component/Timer.cpp \
					src/Core/Component/Mouse.cpp

OBJ_CORE =	$(SRC_CORE:.cpp=.o)

OBJ_TESTS =	$(SRC_CORE_TESTS:.cpp=.o)

CCX =	g++

RM =	rm -rf

LIB_CRITERION = --coverage -lcriterion

NAME_TEST =	unit_tests

NAME_CORE =	arcade

OUTPUT = -o

LIB_DYNAMIC = -ldl

CPPFLAGS = -I./src/

CXXFLAGS = -Wall -Wextra

all: 	core game graphicals

debug:  CPPFLAGS += -g3
debug:  re

core:	$(OBJ_CORE)
		$(CCX) $(OUTPUT) $(NAME_CORE) $(OBJ_CORE) $(LIB_DYNAMIC)

game:
		@make -C ./src/Games

graphicals:
		@make -C ./src/Graphicals

clean:
		$(RM) $(NAME_CORE)
		$(RM) $(OBJ_CORE)
		@make clean -C ./src/Games
		@make clean -C ./src/Graphicals

fclean:	clean tests_clean
		@make fclean -C ./src/Graphicals
		@make fclean -C ./src/Games

re:		fclean tests_clean all

tests_run:		fclean all
				$(CCX) $(CPPFLAGS) -o $(NAME_TEST) $(SRC_CORE_TESTS) $(LIB_CRITERION) $(LIB_DYNAMIC)
				./$(NAME_TEST)

tests_run_xml:	fclean
				$(CCX) $(CPPFLAGS) -o $(NAME_TEST) $(SRC_CORE_TESTS) $(LIB_CRITERION) $(LIB_DYNAMIC)
				./$(NAME_TEST) --xml=test_results.xml

tests_clean:
				$(RM) $(NAME_TEST)
				$(RM) *.gcda
				$(RM) *.gcno
				$(RM) test_results

docs_clean:
				$(RM) docs/_build
				$(RM) docs/doxyxml
				$(RM) docs/latex

docs_make:
				@make html -C ./docs

.PHONY:			all clean fclean re
