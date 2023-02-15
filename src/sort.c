/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:25:13 by kvebers           #+#    #+#             */
/*   Updated: 2023/02/15 12:17:40 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	switch_form(t_data *data)
{
	int	border;

	border = data->argc / 15;
	while (data->stack1_len > 0)
	{
		border = border + data->argc / 16;
		while (data->stack1[data->stack1_start] < border
			&& data->stack1_len != 0)
		{
			if (data->stack1[data->stack1_start] < border - data->argc / 32)
				pb(data);
			else
			{
				pb(data);
				rb(data);
			}
		}
	}
}

void	start_sort(t_data *data)
{
	while (data->stack1_len > 0)
		quick_sort_a(data);
	while (data->stack2[data->stack2_start] > data->median2)
		quick_sort_b(data, data->median2);
	rrb(data);
	while (data->stack2[data->stack2_start] > data->median2)
		quick_sort_b1(data, data->median2);
	while (data->stack1[data->stack1_end - 1] < data->median2 + data->argc / 8)
		rra(data);
	loop_sort(data, data->median);
	loop_sort(data, data->median1);
	while (data->stack2_len >= data->argc / 8)
		quick_sort_b2(data, 1);
	while (data->stack1[data->stack1_end - 1] < data->median2 + data->argc / 8)
		rra(data);
	rrb(data);
	while (data->stack2_len > 0)
		quick_sort_b1(data, 1);
	while (data->stack1[data->stack1_end - 1] < data->median2 + data->argc / 8)
		rra(data);
	switch_form(data);
	while (data->stack2_len > 0)
		push_to_sort(data);
}

void	start_sort1(t_data *data)
{
	while (data->stack1_len > 0)
		quick_sort_a(data);
	while (data->stack2_len > 0)
		push_to_sort(data);
}
