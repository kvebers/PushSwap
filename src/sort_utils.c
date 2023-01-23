/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:08:29 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/20 12:09:42 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_print_stacks(t_data *data)
{
	int	cnt;

	cnt = 0;
	while (cnt < data->malloc_len)
	{
		ft_printf("%i,", data->stack1[cnt]);
		cnt++;
	}
	ft_printf(" ");
	cnt = 0;
	while (cnt < data->malloc_len)
	{
		ft_printf("%i,", data->stack2[cnt]);
		cnt++;
	}
	ft_printf("\n");
}

int	check_sort(t_data *data)
{
	int	cnt;
	int	cnt1;

	cnt = data->stack1_start;
	if (data->stack2_len > 0)
		return (0);
	while (cnt < data->stack1_end - 1)
	{
		cnt1 = cnt + 1;
		while (cnt1 < data->argc + data->stack1_start)
		{
			if (data->stack1[cnt] > data->stack1[cnt1])
				return (0);
			cnt1++;
		}
		cnt++;
	}
	return (1);
}
