/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduvivie <cduvivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 16:43:25 by cduvivie          #+#    #+#             */
/*   Updated: 2021/05/27 06:25:14 by cduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/*
**	Function to sort an ARRAY using insertion sort
*/

void	insertion_sort(int *arr, int size)
{
	int	i;
	int	key;
	int	j;

	i = 1;
	while (i < size)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
		i++;
	}
}

int	find_median(t_checker *arg, t_stack *stack, int size)
{
	int		*array;
	t_list	*cursor;
	int		count;
	int		res;

	count = 0;
	cursor = stack->head;
	array = malloc(sizeof(int) * size);
	if (!array)
		free_and_exit(arg);
	while (cursor && count < size)
	{
		array[count++] = *(int *)cursor->content;
		cursor = cursor->next;
	}
	insertion_sort(array, size);
	res = array[size / 2];
	free(array);
	return (res);
}
