NAME	=   PmergeMe

SRCS 	=	main.cpp \
			PmergeMe.cpp

CC		=	c++

CFLAGS	=	-Wall -Wextra -Werror -std=c++98 -g3

OBJS	=	$(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 

%.o: %.cpp
	$(CC) $(CFLAGS) -I. -c $< -o $@

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f $(NAME)

re:			fclean all

.PHONY:	all clean fclean re