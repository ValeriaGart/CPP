NAME = hi_this_is_brain

SRCS =	main.cpp

CXX = c++

CFLAGS = -Wextra -Werror -Wall -g -std=c++98

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