NAME	= libftprintf.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= ft_printf.c ft_printf_utils.c ft_printf_utils2.c

OBJ_DIR = obj

OBJS    = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re