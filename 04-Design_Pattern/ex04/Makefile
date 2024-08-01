NAME		=	ex04.out
SRC			=	main.cpp
CPP			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -MMD
RM			=	rm -rf
INC			=	-I ../ex00 -I ./
SRC_PATH	=	./
OBJ_PATH	=	./obj/
OBJ_DIRS	=	${OBJ_PATH}
OBJ			=	${addprefix ${OBJ_PATH},${SRC:.cpp=.o}}
DEPS		=	${addprefix ${OBJ_PATH},${SRC:.cpp=.d}}

all:
	make ${NAME}

clean:
	make -C ../ex00 clean
	${RM} ${OBJ_PATH}

fclean:clean
	make -C ../ex00 fclean
	${RM} ${NAME}

re:fclean
	make all

run:re
	clear
	./${NAME}

${OBJ_PATH}%.o:${SRC_PATH}%.cpp
	${CPP} ${CPPFLAGS} ${INC} -c $< -o $@

${OBJ_DIRS}:
	mkdir ${OBJ_DIRS}

${NAME}:${OBJ_DIRS} ${OBJ}
	make -C ../ex00
	${CPP} ${CPPFLAGS} ${OBJ} ../ex00/ex00.a -o $@

.PHONY:all clean fclean re run

-include ${DEPS}
