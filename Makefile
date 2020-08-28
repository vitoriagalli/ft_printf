NAME =		libftprintf.a

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR =	srcs
SRC =		$(SRC_DIR)/ft_printf.c \
			$(SRC_DIR)/print_char.c \
			$(SRC_DIR)/print_string.c \
			$(SRC_DIR)/print_int.c \
			$(SRC_DIR)/print_pointer.c \
			$(SRC_DIR)/print_percent.c \
			$(SRC_DIR)/store_flags.c

OBJ_DIR =	objs
OBJ =		$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

HEAD =		-I. -I./$(LIBFT_DIR)
CFLAGS =	-Wall -Werror -Wextra -g
LFLAGS =	-L . -lftprintf

CC = clang
RM = /bin/rm -rf

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	ar rc $(NAME) $(OBJ)
	ranlib $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(HEAD) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(OBJ_DIR)
	$(RM) $(NAME)

re: fclean all

.PONY: all, clean, fclean, re
