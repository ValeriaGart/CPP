NAME = phonebook

SRCS =	phonebook_class.cpp	\
		contact_class.cpp	\
		main.cpp

CXX = c++

CFLAGS = -Wextra -Werror -Wall -g

OBJS = $(SRCS:.cpp=.o)

all:    $(NAME)

$(NAME): $(OBJS)
		c++ -o $(NAME) $(CFLAGS) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re