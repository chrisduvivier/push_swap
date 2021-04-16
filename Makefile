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

CHECKER		:=	checker
PUSH_SWAP	:=	push_swap

CC 			:=	gcc
CFLAGS	 	:=	-Wall -Wextra -Werror
RM 			:=	/bin/rm -f

LIBFT		:= libft/libft.a

# C filenames of the project
SRCS 		:= 	ft_checker_helper.c \
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

OBJ			:=	$(SRCS:%.c=%.o)

all			:	$(CHECKER) $(PUSH_SWAP)

$(CHECKER)	:	$(OBJ) $(LIBFT)
	@ $(CC) $(CFLAGS) ft_checker.c $(SRCS) -o $(CHECKER) $(LIBFT)
	
$(PUSH_SWAP): 	$(OBJ) $(LIBFT)
	@ $(CC) $(CFLAGS) ft_push_swap.c $(SRCS) -o $(PUSH_SWAP) $(LIBFT)

$(LIBFT)	:
	@ $(MAKE) -C ./libft

clean		:
	@ $(RM) $(OBJ)
	@ $(MAKE) -C ./libft clean

fclean		:	clean
	@ $(RM) $(CHECKER) $(PUSH_SWAP)
	@ $(MAKE) -C ./libft fclean

re			: fclean all

.PHONY		: all clean fclean re