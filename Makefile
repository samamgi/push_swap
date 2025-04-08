# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 16:49:14 by ssadi-ou          #+#    #+#              #
#    Updated: 2025/04/08 17:08:46 by ssadi-ou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =		main/init.c \
		main/main.c \
		src/sort.c \
		utils/instructions_push.c \
		utils/instructions_reverse_rotate.c \
		utils/instructions_rotate.c \
		utils/instructions_swap.c \
		utils/lst_funcs_2.c \
		utils/lst_funcs.c\
		utils/utils.c \
		utils/utils_2.c \

NAME =		push_swap


CFLAGS =	-Wall -Werror -Wextra -g3

CC =		cc

OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft

FT_PRINTF_DIR = ft_printf

LIBFT_OBJ = $(LIBFT_DIR)/libft.a

FT_PRINTF_OBJ = $(FT_PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_OBJ) $(FT_PRINTF_OBJ)
		$(CC) $(CFLAGS) -o $@ $^ 

%.o: %.c inc/push_swap.h
		$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_OBJ):
		$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF_OBJ):
		$(MAKE) -C $(FT_PRINTF_DIR)

clean:
		rm -f $(OBJ)
		$(MAKE) -C $(LIBFT_DIR) clean
		$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
		rm -f $(NAME)
		$(MAKE) -C $(LIBFT_DIR) fclean
		$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: clean fclean all re bonus
