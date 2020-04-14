# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vscabell <vscabell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/06 20:01:13 by vscabell          #+#    #+#              #
#    Updated: 2020/04/14 14:42:30 by vscabell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = src/ft_printf.c src/ft_print_diux.c src/ft_print_percent.c \
	src/ft_print_char.c src/ft_print_string.c src/ft_print_pointer.c \
	src/ft_check_flags.c src/ft_hold_flags.c src/ft_reinit_var.c \
	utils/ft_calloc_char.c utils/ft_isdigit.c utils/ft_isspecifier.c \
	utils/ft_itoa_base.c utils/ft_itoa_ptr.c utils/ft_memcpy.c \
	utils/ft_memset.c utils/ft_putchar.c utils/ft_putstr.c \
	utils/ft_strdup.c utils/ft_strlen.c utils/ft_strjoin.c \

OBJ = ft_printf.o ft_print_diux.o ft_print_percent.o \
	ft_print_char.o ft_print_string.o ft_print_pointer.o \
	ft_check_flags.o ft_hold_flags.o ft_reinit_var.o \
	ft_calloc_char.o ft_isdigit.o ft_isspecifier.o \
	ft_itoa_base.o ft_itoa_ptr.o ft_memcpy.o \
	ft_memset.o ft_putchar.o ft_putstr.o \
	ft_strdup.o ft_strlen.o ft_strjoin.o \

INCLUDES = include

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = /bin/rm -f

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re