NAME = donto_man
SRCS = main.c src/command.c src/repl.c src/exit_command.c \
	   src/veloma_command.c src/help_command.c src/clear_command.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g -O2
INCLUDES = -I./includes

all: $(NAME)

$(NAME): $(OBJS)
	@cc $(CFLAGS) $(OBJS) -o $(NAME)

clean: $(OBJS)
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
