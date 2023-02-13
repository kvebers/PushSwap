/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:27:44 by kvebers           #+#    #+#             */
/*   Updated: 2023/02/12 20:12:07 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	quick_sort_b(t_data *data, int median)
{
	if (data->stack2[data->stack2_start] >= median + data->argc / 16 * 3)
	{
		pa(data);
		ra(data);
	}
	else if (data->stack2[data->stack2_start] >= median + data->argc / 8
		&& data->stack2[data->stack2_start] <= median + data->argc / 16 * 3)
	{
		pa(data);
	}
	else
		rb(data);
}

void	quick_sort_b1(t_data *data, int median)
{
	if (data->stack2[data->stack2_start] >= median + data->argc / 16)
	{
		pa(data);
	}
	else if (data->stack2[data->stack2_start] >= median
		&& data->stack2[data->stack2_start] <= median + data->argc / 16)
	{
		pa(data);
		ra(data);
	}
	if (data->stack2[data->stack2_end - 1] >= median)
		rrb(data);
}

void	quick_sort_b2(t_data *data, int median)
{
	if (data->stack2[data->stack2_start] >= median + data->argc / 16 * 3)
	{
		pa(data);
	}
	else if (data->stack2[data->stack2_start] >= median + data->argc / 8 - 1
		&& data->stack2[data->stack2_start] <= median + data->argc / 16 * 3)
	{
		pa(data);
		ra(data);
	}
	else
		rb(data);
}

void	loop_sort(t_data *data, int median)
{
	while (data->stack2[data->stack2_start] >= median)
		quick_sort_b2(data, median);
	while (data->stack1[data->stack1_end - 1] < data->median2 + data->argc / 8)
		rra(data);
	rrb(data);
	while (data->stack2[data->stack2_start] >= median)
		quick_sort_b1(data, median);
	while (data->stack1[data->stack1_end - 1] < data->median2 + data->argc / 8)
		rra(data);
}
