SRC = srcs/ft_parsing_flags.c \
srcs/ft_parsing_type.c \
srcs/ft_parsing_type_hex.c \
srcs/ft_parsing_type_ui.c \
srcs/ft_print.c \
srcs/ft_printf.c \
srcs/ft_str_convert.c \
srcs/ft_treat_dot.c \
srcs/ft_treat_mfw.c \
srcs/ft_treat_zero.c \
srcs/printf_utils.c \
srcs/printf_utils2.c
LIBFT = ./libft
IFLAGS = -I includes/
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
CC = gcc
OBJ = $(SRC:.c=.o)
HEADER = includes/ft_printf.h
LIBR = ./libft
all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJ) ${HEADER} ${LIBR}
		@make -C ${LIBFT}
		@cp libft/libft.a ./${NAME}
		ar rcs ${NAME} ${OBJ}
		ranlib ${NAME}

%.o:%.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	@make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean res
