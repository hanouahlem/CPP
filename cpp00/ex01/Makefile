NAME	= 	phonebook

SRCS 	=	PhoneBook.cpp \
			Contact.cpp \
			main.cpp \

CC		=	c++

CFLAGS	=	-Wall -Wextra -Werror -g3 -std=c++98

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