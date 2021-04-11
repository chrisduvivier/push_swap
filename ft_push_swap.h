/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduvivie <cduvivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 14:28:02 by cduvivie          #+#    #+#             */
/*   Updated: 2021/04/11 17:23:37 by cduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_checker
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		max_size;
	char	*logs;
}			t_checker;

void	ft_stack_print(t_stack *stack);
void	check_operations(t_checker *checker_arg);
int		find_duplicate(int size, char *argv[]);
void	error_exit(t_checker *checker_arg);
int		free_and_exit(t_checker *checker_arg);
void	handle_operation(t_checker *checker_arg, char *line);
int		stack_is_sorted(t_stack *stack);

int		checker_atoi(const char *str, t_checker *checker_arg);
int		free_and_exit(t_checker *checker_arg);
void	error_exit(t_checker *checker_arg);
void	checker_arg_init(t_checker *checker_arg);

void	swap_stack(t_stack *stack);
void	push_stack(t_stack *stack_src, t_stack *stack_dst);
void	rotate_stack(t_stack *stack);
void	reverse_rotate_stack(t_stack *stack);

int		checker_parse_arg(int argc, char **argv,
			t_checker *checker_arg);
void	ft_stack_parser_push(t_stack *stack, t_list *node);
int		free_and_exit(t_checker *checker_arg);
void	error_exit(t_checker *checker_arg);

void	print_stacks(t_checker *arg);

void	simple_sort(t_checker *arg);
void	sort_three_number(t_checker *arg);
void	sort_top_two_number(t_checker *arg, char stack_type);
void	sort_top_three_number(t_checker *arg);
void	sort_less_than_five_number(t_checker *arg, int size);
void	quick_sort(t_checker *arg, int n);
void	quick_sort_helper_large(t_checker *arg, int n, int *top_half_len);
void	quick_sort_helper_small(t_checker *arg, int n, int *top_half_len);
int		find_median(t_checker *arg, t_stack *stack, int size);
void	insertion_sort(int *arr, int size);

void	ft_stack_pa(t_checker *arg);
void	ft_stack_pb(t_checker *arg);
void	ft_stack_ra(t_checker *arg);
void	ft_stack_rb(t_checker *arg);
void	ft_stack_rra(t_checker *arg);
void	ft_stack_rrb(t_checker *arg);
void	ft_stack_sa(t_checker *arg);
void	ft_stack_sb(t_checker *arg);

#endif