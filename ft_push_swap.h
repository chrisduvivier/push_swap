/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduvivie <cduvivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 14:28:02 by cduvivie          #+#    #+#             */
/*   Updated: 2021/03/14 08:04:34 by cduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "libft/libft.h"
typedef struct	s_stack
{
	size_t		size;
	t_list		*head;
	t_list		*tail;
}				t_stack;

typedef struct	s_checker
{
	t_stack		*stack_a;
	t_stack		*stack_b;
}				t_checker;

// TO ADD TO LIBFT ============
void	ft_stack_push(t_stack *stack, t_list *node);
t_list  *ft_stack_pop(t_stack *stack);


// ============================

void 	ft_stack_print(t_stack *stack);
void    check_operations(t_checker *checker_arg);
int     find_duplicate(int size, char *argv[]);
void	error_exit(t_checker *checker_arg);
int		free_and_exit(t_checker *checker_arg);

void    swap_stack(t_stack *stack);
void    push_stack(t_stack *stack_src, t_stack *stack_dst);
void    rotate_stack(t_stack *stack);
void    reverse_rotate_stack(t_stack *stack);

#endif