##
## EPITECH PROJECT, 2021
## B-MAT-400-STG-4-1-201yams-clement.muth [WSL: Ubuntu]
## File description:
## Makefile
##

CXX	=	g++

RM	=	rm -f

SRC	=	sources/main.cpp	\
		sources/operand.cpp	\
		sources/utils.cpp

NAME	=	201yams

CXXFLAGS	=	-I./includes -lm

OBJS	=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME) $(CXXFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
