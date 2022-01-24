NAME = fractol
MAIN = fractol.c
HEADER = fractol.h

CC = gcc
CC_F = -Wall -Werror -Wextra
MLX = -lmlx -framework OpenGL -framework Appkit

LIBFT = libft/libft.a
LIBPATH = libft/

SRCS = fractol.c, fractals.c, mouse.c, keys.c, utils.c, draw.c

OBJ_NAME = $(SRCS:.c=.o)
OBJ_BONUS_NAME = $(SRCS:.c=.o)

all:
	@$(MAKE) -C $(LIBPATH)
	@$(MAKE) $(NAME)
$(NAME): $(OBJ_NAME) $(HEADER) $(LIBFT) Makefile
	@$(CC) $(CC_F) $(LIBFT) $(MLX) $(OBJ_NAME) -o $(NAME)

bonus: all

clean:
	@$(MAKE) -C $(LIBPATH) clean
	@rm -f $(OBJ_NAME)
fclean:
	@$(MAKE) -C $(LIBPATH) fclean
	@rm -f $(OBJ_NAME)
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re bonus