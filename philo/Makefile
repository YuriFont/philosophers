NAME = philo
SOURCE = ./source/
PHILOSOPHERS = $(SOURCE)philosophers.c\
		$(SOURCE)utils.c\
		$(SOURCE)check_args.c\
		$(SOURCE)init_dining.c\
		$(SOURCE)handles.c\
		$(SOURCE)can_eat.c\
		$(SOURCE)actions.c
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(PHILOSOPHERS) -o $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
