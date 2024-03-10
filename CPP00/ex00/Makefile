NAME = megaphone

SRCS = megaphone.cpp

CXX = c++

CFLAGS = -Wextra -Werror -Wall

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