NAME		=	ex01.out
SRC			=	main.cpp
CPP			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98 -MMD -g3
RM			=	rm -rf
INC			=	-I ./
SRC_PATH	=	./
OBJ_PATH	=	./obj/
OBJ_DIRS	=	${OBJ_PATH}
OBJ			=	${addprefix ${OBJ_PATH},${SRC:.cpp=.o}}
DEPS		=	${addprefix ${OBJ_PATH},${SRC:.cpp=.d}}

all:
	make ${NAME}

clean:
	${RM} ${OBJ_PATH}

fclean:clean
	${RM} ${NAME}

re:fclean
	make all

run:${NAME}
	clear
	./${NAME}

${OBJ_PATH}%.o:${SRC_PATH}%.cpp
	${CPP} ${CPPFLAGS} ${INC} -c $< -o $@

${OBJ_DIRS}:
	mkdir ${OBJ_DIRS}

${NAME}:${OBJ_DIRS} ${OBJ}
	${CPP} ${OBJ} -lpng -o $@

.PHONY:all clean fclean re run

-include ${DEPS}
