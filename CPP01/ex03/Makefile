NAME = unnecessary_violence

SRCS =	main.cpp	\
		HumanA.cpp	\
		HumanB.cpp	\
		Weapon.cpp

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