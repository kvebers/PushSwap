/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:25:13 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/25 17:57:52 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	sort_segment_a_b(t_data *data, int median)
{
	int	cnt;

	cnt = 1;
	while (cnt < 2)
	{
		while (data->stack1[data->stack1_start] > median + data->argc / 16 * (4 - cnt) + data->argc / 64)
		{
			if (data->stack1[data->stack1_start] >= median + data->argc / 16 * (4 - cnt) + data->argc / 64 * 4)
			{
				pb(data);
				rb(data);
			}
			else if ((data->stack1[data->stack1_start] >= median + data->argc / 16 * (4 - cnt) + data->argc / 64 * 3)
			&& (data->stack1[data->stack1_start] <= median + data->argc / 16 * (4 - cnt) + data->argc / 64 * 4))
				pb(data);
			else
				ra(data);
		}
		while (data->stack1[data->stack1_end] > median + data->argc / 16 * (4 - cnt) + data->argc / 64)
		{
			rra(data);
		//	pb(data);
		}
		cnt++;
	}
}

void	start_sort(t_data *data)
{
	while (data->stack1_len > 0)
		quick_sort_a(data);
	while (data->stack2[data->stack2_start] > data->median2)
		sort_segment_b_a(data, data->median2);
	while (data->stack2[data->stack2_end - 1] > data->median2)
		sort_segment_b_a1(data, data->median2);
	sort_segment_a_b(data, data->median2);
}

