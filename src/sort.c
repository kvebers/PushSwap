/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:25:13 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/23 17:18:11 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	quick_sort_a1(t_data *data)
{
	if (data->stack1[data->stack1_start] >= data->median)
		pb(data);
	else if (data->stack1[data->stack1_start] < data->median)
	{
		pb(data);
		rb(data);
	}
}

int	check_medians(t_data *data)
{
	int	cnt;

	cnt = data->stack1_start;
	while (cnt < data->stack1_end)
	{
		if (data->stack1[cnt] > data->median1
			&& data->stack1[cnt] <= data->median2)
			return (0);
		cnt++;
	}
	return (1);
}

void	quick_sort_a(t_data *data)
{
	if (data->stack1[data->stack1_start] >= data->median
		&& data->stack1[data->stack1_start] <= data->median2)
		pb(data);
	else if (data->stack1[data->stack1_start] <= data->median
		&& data->stack1[data->stack1_start] > data->median1)
	{
		pb(data);
		rb(data);
	}
	else if (check_medians(data) == 1)
		quick_sort_a1(data);
	else
		ra(data);
}

void	calculate_median(t_data *data)
{
	data->median = data->seg_width / 2;
	data->median1 = data->seg_width / 4;
	data->median2 = data->seg_width * 3 / 4;
}

void	quick_sort_b(t_data *data, int offset)
{
	if (data->stack2[data->stack2_start] >= offset + data->median && data->stack2[data->stack2_start] < offset + data->median1 + data->median)
	{	
		pa(data);
		ra(data);
	}
	else if (data->stack2[data->stack2_start] >= data->median1 + offset && data->stack2[data->stack2_start] <= offset + data->median)
		pa(data);
	else
		rb(data);
}

void	quick_sort_b1(t_data *data, int offset)
{
	if (data->stack2[data->stack2_start] <= offset + data->median && data->stack2[data->stack2_start] > offset)
	{	
		pa(data);
		rrb(data);
	}
	else if (data->stack2[data->stack2_start] >= offset + data->median)
	{
		pa(data);
		rrb(data);
		ra(data);
	}
	else
		rrb(data);
}

void	start_sort(t_data *data)
{
	int	cnt;

	while (data->stack1_len > 0)
		quick_sort_a(data);
	cnt = 1;
	while (cnt < 2)
	{
		if (cnt > 1)
			data->seg_width = data->seg_width * 4;
		calculate_median(data);
		while (data->stack2[data->stack2_start] > data->argc
			- data->seg_width * (cnt))
			quick_sort_b(data, data->argc - data->seg_width * cnt);
			rrb(data);
		while (data->stack2[data->stack2_start] > data->argc
			- data->seg_width * (cnt))
			quick_sort_b1(data, data->argc - data->seg_width * cnt);
		rb(data);
		data->seg_width = data->seg_width / 4;
		calculate_median(data);
		cnt++;
	}
}
