NAME = easy_find

SRCS =	main.cpp	

CC = c++

CFLAGS = -std=c++98 -pedantic -Wextra -Werror -Wall

OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
		$(CC) -o $(NAME) $(CFLAGS) $(OBJS)

all:    $(NAME)

%.o: %.c
		$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re