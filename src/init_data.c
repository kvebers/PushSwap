/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:54:06 by kvebers           #+#    #+#             */
/*   Updated: 2023/02/17 13:38:30 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	init_arrays(t_data *data)
{
	int	cnt;

	cnt = 0;
	data->stack1 = malloc(data->malloc_len * sizeof(int));
	if (data->stack1 == NULL)
		return (free(data->stack), 0);
	data->stack2 = malloc(data->malloc_len * sizeof(int));
	if (data->stack2 == NULL)
		return (free(data->stack), free(data->stack1), 0);
	while (cnt < data->malloc_len)
	{
		data->stack1[cnt] = 0;
		data->stack2[cnt] = 0;
		cnt++;
	}
	return (1);
}

int	transform_stack(t_data *data)
{
	int	*place_holder;
	int	cnt;
	int	cnt1;
	int	sum;

	place_holder = malloc(sizeof(int) * (data->argc + 1));
	if (place_holder == NULL)
		return (0);
	cnt = 0;
	while (cnt < data->argc)
	{
		cnt1 = -1;
		sum = 0;
		while (++cnt1 < data->argc)
		{
			if (data->stack[cnt] >= data->stack[cnt1])
				sum++;
		}
		place_holder[cnt] = sum;
		cnt++;
	}
	cnt = -1;
	while (cnt++ < data->argc - 1)
		data->stack[cnt] = place_holder[cnt];
	return (free(place_holder), 1);
}

void	init_stacks(t_data *data)
{
	int	cnt;

	data->stack1_start = data->malloc_len / 4;
	data->stack2_start = data->malloc_len / 4 * 3;
	data->stack2_end = data->stack2_start;
	data->stack2_len = data->stack2_end - data->stack2_start;
	data->stack1_end = data->stack1_start;
	data->median = data->argc / 2;
	data->median1 = data->argc / 2 - data->argc / 4;
	data->median2 = data->argc / 2 + data->argc / 4;
	data->seg_width = data->argc / 4;
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
	data->malloc_len = data->argc * 4;
	if (transform_stack(data) == 0 || init_arrays(data) == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	init_stacks(data);
	return (1);
}
