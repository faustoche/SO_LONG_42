##### COMPILATION #####

CC          = cc
CFLAGS      = -Wall -Werror -Wextra -g3
MLX_PATH    = minilibx-linux
MLX_LIB     = $(MLX_PATH)/libmlx_Linux.a
MLX_FLAGS   = -L$(MLX_PATH) -lmlx_Linux -lXext -lX11 -lm -lz

##### UTILE #####

RM = rm -rf

NAME = so_long

##### OBJETS #####

LIBC = ft_printf/ft_printf.c\
				ft_printf/ft_putc.c\
				ft_printf/ft_putdi.c\
				ft_printf/ft_putp.c\
				ft_printf/ft_puts.c\
				ft_printf/ft_putun.c\
				ft_printf/ft_putx.c\
				path_checker.c\
				map_checker.c\
				symbol_checker.c\
				map_allocation.c\
				error_display.c\
				error_map.c\
				grid.c\
				init_enemies_bonus.c\
				init_images.c input.c\
				main.c\
				map_parsing.c\
				move_displayed.c\
				open_close_win.c\
				get_next_line/get_next_line_utils.c\
				get_next_line/get_next_line.c

##### INGREDIENTS #####

SRCS = ${LIBC}
OBJS = ${SRCS:.c=.o}

##### COULEURS #####

COLOR_RESET = \033[0m
COLOR_GREENB = \033[0;32m
COLOR_REDB = \033[1;91m

##### PROCESS #####

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[0;33m\n🦖 COMPILING SO_LONG... 🦖\n"
	$(CC) $(OBJS) -o $(NAME) $(MLX_FLAGS)
	@echo "\033[1;32m🦖 ./$(NAME) created 🦖\n"

clean:
	@echo "\033[0;31m🗑️  Deleting Object files... 🗑️\n"
	@rm -f $(OBJS)
	@echo "\033[1;32m✅ Done ✅\n"

fclean: clean
	@echo "\033[0;31m🗑️  Deleting $(NAME)... 🗑️"
	@rm -f $(NAME)
	@echo "\033[1;32m✅ Done ✅\n"

re: fclean all

.PHONY: all clean fclean re
