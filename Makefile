# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cduvivie <cduvivie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/07 21:00:40 by cduvivie          #+#    #+#              #
#    Updated: 2021/03/13 14:59:00 by cduvivie         ###   ########.fr        #
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
FILES = ft_checker.c ft_checker_operations_1.c

OBJ	= $(FILES:%.c=%.o)

all: $(NAME_EXEC_1)

$(NAME_EXEC_1): lib $(OBJ)
	
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