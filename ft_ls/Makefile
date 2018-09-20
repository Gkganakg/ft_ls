# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/04 14:18:48 by gkganakg          #+#    #+#              #
#    Updated: 2018/09/08 10:11:41 by gkganakg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

NAME  = ft_ls

LIBFT_PATH = libft/

PRINTF_PATH = ft_printf/

SRC = 	main.c \
		check_args.c\
		print_permission.c \
		print_mode.c \
		list.c \
		list2.c \
		ft_time.c \
		print_options.c \
		beat_normm.c\
		

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	@make -C $(LIBFT_PATH)
	@make -C $(PRINTF_PATH)
	@gcc -o $(NAME)  $(FLAG) $(SRC)  libft/libft.a ft_printf/libftprintf.a
	@echo "objects created .... succesfuly"
	@echo "ft_ls.a created ... succesfully"

norm:
	@norminette -R CheckForbiddenSourceHeader main.c print_permission.c print_mode.c \
        list.c list2.c ft_time.c print_options.c beat_normm.c   ft_ls.h

clean:
	@make -C $(LIBFT_PATH)  / clean
	@make  -C $(PRINTF_PATH) / clean
	@rm -f $(OBJ)
	@echo "Objects cleaned... succesfully"

fclean: clean
	@rm -f $(NAME)
	@echo "Objects and library cleaned ... succesfully"

re: fclean all

.PHONY: all, clean, fclean, re, norm
