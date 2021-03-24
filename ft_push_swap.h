/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduvivie <cduvivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 14:28:02 by cduvivie          #+#    #+#             */
/*   Updated: 2021/03/22 22:42:05 by cduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "libft/libft.h"

typedef struct	s_checker
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			max_size;
}				t_checker;

void 	ft_stack_print(t_stack *stack);
void    check_operations(t_checker *checker_arg);
int     find_duplicate(int size, char *argv[]);
void	error_exit(t_checker *checker_arg);
int		free_and_exit(t_checker *checker_arg);
void	handle_operation(t_checker *checker_arg, char *line);
int		stack_is_sorted(t_stack *stack);

int		checker_atoi(const char *str, t_checker *checker_arg);
int		free_and_exit(t_checker *checker_arg);
void	error_exit(t_checker *checker_arg);
void	checker_arg_init(t_checker *checker_arg);

void	print_list_int(void *content);
void	ft_stack_print(t_stack *stack);

void    swap_stack(t_stack *stack);
void    push_stack(t_stack *stack_src, t_stack *stack_dst);
void    rotate_stack(t_stack *stack);
void    reverse_rotate_stack(t_stack *stack);

int		checker_parse_arg(int argc, char *argv[], 
		t_checker *checker_arg);
int		free_and_exit(t_checker *checker_arg);
void	error_exit(t_checker *checker_arg);

void	print_stacks(t_checker *arg);

void	quick_sort(t_checker *arg, int n);
void	quick_sort_helper_large(t_checker *arg, int n, int *top_half_len);
void	quick_sort_helper_small(t_checker *arg, int n, int *top_half_len);

#endif