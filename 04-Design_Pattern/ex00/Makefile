NAME		=	ex00.out
LIB			=	ex00.a
SRC			=	Course.cpp Form.cpp Person.cpp Room.cpp
CPP			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -MMD
AR			=	ar -r
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
	${RM} ${NAME} ${LIB}

re:fclean
	make all

run:${NAME}
	${CPP} ${CPPFLAGS} ${INC} -c main.cpp -o obj/main.o
	${CPP} ${CPPFLAGS} ${OBJ} ./obj/main.o -o ${NAME}
	clear
	./${NAME}

${OBJ_PATH}%.o:${SRC_PATH}%.cpp
	${CPP} ${CPPFLAGS} ${INC} -c $< -o $@

${OBJ_DIRS}:
	mkdir ${OBJ_DIRS}

${NAME}:${OBJ_DIRS} ${OBJ}
	${AR} ${LIB} ${OBJ}

.PHONY:all clean fclean re run

-include ${DEPS}
