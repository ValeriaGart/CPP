NAME = moar_brainz

SRCS =	main.cpp		\
		Zombie.cpp		\
		zombieHorde.cpp

CXX = c++

CFLAGS = -Wextra -Werror -Wall -g -std=c++98 -pedantic

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