/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:25:13 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/24 16:07:03 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	calculate_median(t_data *data)
{
	data->median = data->seg_width / 2;
	data->median1 = data->seg_width / 4;
	data->median2 = data->seg_width * 3 / 4;
}

void	sort_sub_a(t_data *data, int offset)
{
	int	cnt;

	data->seg_width = data->seg_width / 4;
	calculate_median(data);
	cnt = 3;
	if (offset == data->argc / 4)
		offset = 0;
	while (data->stack1_len > 0)
	{
		while (data->stack1[data->stack1_start] > data->argc
				- (4 - cnt) * data->seg_width)
		{
			if (data->stack1[data->stack1_start] > data->argc
				- (4 - cnt) * data->seg_width + data->median - offset)
			{
				pb(data);
				rb(data);
			}
			else if (data->stack1[data->stack1_start] < data->argc
				- (4 - cnt) * data->seg_width + data->median - offset
				&& data->stack1[data->stack1_start] > data->argc
				- (4 - cnt) * data->seg_width - offset)
				pb(data);
			else
				ra(data);
		}
		while (data)
		
		cnt--;
	}
}

void	start_sort(t_data *data)
{
	int	cnt;

	while (data->stack1_len > 0)
		quick_sort_a(data);
	cnt = 1;
	while (cnt < 3)
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
		sort_sub_a(data, data->seg_width * cnt);
		cnt++;
	}
}
