CC		= cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -lXext -lX11
SRCS = get_next_line.c get_next_line_utils.c map_check.c map_destroy.c \
	   map_load.c so_long.c utils.c map_valid_path.c map_render.c movements.c \
	   finish.c
OBJS = $(SRCS:.c=.o)
NAME = so_long
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re