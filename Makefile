
# Nom de l'exécutable
NAME = philo

# Compilateur et options
CC = cc
HEADER = Includes/
CFLAGS = -pthread -I ${HEADER}

# -fsanitize=thread

# Fichiers sources et objets
SRCS = src/main.c\
		src/parsing.c\
		src/contexts_manager/ctx.c\
		src/contexts_manager/free_ctx.c\
		src/contexts_manager/safe_free.c\
		src/contexts_manager/safe_malloc.c\
		src/contexts_manager/manage_level_ctx.c\
		src/data_init.c\
		src/create_table.c\
		src/routine.c\
		src/safe.c\
		src/time.c\
		src/action.c\
		src/monitor.c\
		src/utils.c
OBJS = $(SRCS:.c=.o)
# Commandes
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
