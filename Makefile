# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cduvivie <cduvivie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/07 21:00:40 by cduvivie          #+#    #+#              #
#    Updated: 2021/04/10 17:21:42 by cduvivie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_EXEC_1 := checker
NAME_EXEC_2 := push_swap

CC = gcc
CFLAGS = -I. -c
OPTIONS = -Wall -Wextra -Werror
RM = /bin/rm -f

LIBFT_DIR = libft/

# C filenames of the project
FILES = 	ft_checker_helper.c \
			ft_find_duplicate.c \
			ft_handle_operations.c \
			ft_stack_operations.c \
			ft_stack_helper.c \
			ft_checker_exit.c \
			ft_quick_sort.c \
			ft_simple_sort.c \
			ft_sort_five.c \
			ft_sort_three.c \
			ft_keep_logs_1.c \
			ft_keep_logs_2.c \

OBJ	= $(FILES:%.c=%.o)

all: $(NAME_EXEC_1) $(NAME_EXEC_2)

$(NAME_EXEC_1): lib $(OBJ)
	$(CC) $(OPTIONS) libft.a ft_checker.c $(FILES) -o $(NAME_EXEC_1)
	
$(NAME_EXEC_2): lib $(OBJ)
	$(CC) $(OPTIONS) libft.a ft_push_swap.c $(FILES) -o $(NAME_EXEC_2)

$(OBJ): $(FILES)
	@ $(CC) $(CFLAGS) $(FILES) -Iincludes

lib:
	@ $(MAKE) -C $(LIBFT_DIR) all
	@ cp $(LIBFT_DIR)/libft.a ./

clean:
	@ $(RM) $(OBJ)

fclean: clean
	@ $(RM) $(NAME)
	@ $(RM) libft.a
	@ $(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re