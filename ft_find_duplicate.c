/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_duplicate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduvivie <cduvivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 20:20:25 by cduvivie          #+#    #+#             */
/*   Updated: 2021/03/15 12:01:31 by cduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_push_swap.h"


/*
**  find duplicate in command line argument argv (so we skip 1st)
**  O(n^2) runnnig time
*/
int     find_duplicate(int size, char *argv[])
{
    int i = 1;
    int j;
    while (i < size)
    {
        j = i + 1;
        while (j < size)
        {
            if (ft_strcmp(argv[i], argv[j]) == 0)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}
