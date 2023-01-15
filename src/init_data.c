/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:54:06 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/15 16:38:21 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	init_arrays(t_data *data)
{
	int	cnt;

	cnt = 0;
	data->stack1 = malloc(data->malloc_len * sizeof(int));
	if (data->stack1 == NULL)
		return (0);
	data->stack2 = malloc(data->malloc_len * sizeof(int));
	if (data->stack2 == NULL)
		return (free(data->stack1), 0);
	while (cnt < data->malloc_len)
	{
		data->stack1[cnt] = 0;
		data->stack2[cnt] = 0;
		cnt++;
	}
	data->step = 0;
	return (1);
}

void	init_stacks(t_data *data)
{
	int	cnt;

	data->stack1_start = data->malloc_len / 4;
	data->stack2_start = data->malloc_len / 4 * 3;
	data->stack2_end = data->stack2_start;
	data->stack2_len = data->stack2_end - data->stack2_start;
	data->stack1_end = data->stack1_start;
	data->x = 1;
	data->split_val = 0;
	cnt = 0;
	while (cnt < data->argc)
	{
		data->stack1[data->stack1_end] = data->stack[cnt];
		data->stack1_end++;
		cnt++;
	}
	data->stack1_len = data->stack1_end - data->stack1_start;
}

int	init_data(t_data *data)
{
	data->malloc_len = data->argc * 2;
	if (init_arrays(data) == 0)
	{
		ft_printf("Allocation failed");
		return (0);
	}
	init_stacks(data);
	return (1);
}
