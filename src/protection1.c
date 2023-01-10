/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protection1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:33:53 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/10 15:02:31 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	protection6(int *stack, int argc)
{
	int	cnt;
	int	cnt1;

	cnt = 0;
	while (cnt < argc)
	{
		cnt1 = cnt + 1;
		while (cnt1 < argc)
		{
			if (stack[cnt] == stack[cnt1])
				return (0);
			cnt1++;
		}
		cnt++;
	}
	return (1);
}

int	protection5(int argc, char **argv)
{
	int	cnt;
	int	*stack;

	cnt = 1;
	stack = malloc(sizeof(int) * argc - 1);
	if (stack == NULL)
		return (0);
	while (cnt < argc)
	{
		stack[cnt - 1] = ft_atoi(argv[cnt]);
		cnt++;
	}
	if (protection6(stack, argc - 1) == 0)
		return (free(stack), 0);
	return (free(stack), 1);
}