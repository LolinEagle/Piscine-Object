NAME		=	train.out
SRC			=	main.cpp\
				Place/City.cpp\
				Place/Rail.cpp\
				Place/RailNode.cpp\
				Train/Facade.cpp\
				Train/Overtaking.cpp\
				Train/Train.cpp
CPP			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -MMD
RM			=	rm -rf
INC			=	-I. -I./Place -I./Train
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

run:all
	clear
	valgrind ./${NAME}

${OBJ_PATH}%.o:${SRC_PATH}%.cpp
	${CPP} ${CPPFLAGS} ${INC} -c $< -o $@

${OBJ_DIRS}:
	mkdir ${OBJ_DIRS} ${OBJ_DIRS}/Place ${OBJ_DIRS}/Train

${NAME}:${OBJ_DIRS} ${OBJ}
	${CPP} ${CPPFLAGS} ${OBJ} -o $@

.PHONY:all clean fclean re run

-include ${DEPS}
