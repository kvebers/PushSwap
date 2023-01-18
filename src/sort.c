/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:25:13 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/18 17:09:55 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	push_median(t_data *data)
{
	int	cnt;
	int	cnt1;
	int	sum;

	cnt = data->stack1_start;
	cnt1 = data->stack1_start;
	sum = 0;
	while (cnt < data->stack1_end)
	{
		if (data->stack1[cnt1] > data->stack1[cnt])
			sum++;
		cnt++;
	}
	if (sum >= data->argc - data->seg_width * (data->x_done + 1))
	{
		pb(data);
		data->seg_proc++;
	}
	else if (data->direction == 0)
		ra(data);
}

void	push_median1(t_data *data)
{
	int	cnt;
	int	cnt1;
	int	sum;

	cnt = data->stack1_start;
	cnt1 = data->stack1_start;
	sum = 0;
	while (cnt < data->stack1_end)
	{
		if (data->stack1[cnt1] > data->stack1[cnt])
			sum++;
		cnt++;
	}
	if (sum <= data->seg_width * (data->x_done + 2))
	{
		pb(data);
		data->seg_proc++;
	}
	else if (data->direction == 1)
		rra(data);
}

void	update_stuff(t_data *data)
{
	if (data->direction == 0)
		data->direction = 1;
	else if (data->direction == 1)
	{
		data->direction = 0;
		data->x_done++;
	}
	data->seg_proc = 0;
	if (data->x - data->x_done == 1)
		data->seg_width = data->argc
			- data->x_done * data->seg_width;
}

void	rev_push_utils(t_data *data, int temp, int temp1)
{
	if (temp1 == temp)
	{
		pa(data);
		if (data->swap == 1)
		{
			sa(data);
			data->swap = 0;
		}
	}
	else if (temp >= data->stack2_len / 2 + data->stack2_start)
		rrb(data);
	else if (temp < data->stack2_len / 2 + data->stack2_start)
		rb(data);
	else if (temp1 == data->stack2_start && data->swap == 0)
	{
		pa(data);
		data->swap = 1;
	}
}

void	rev_push_seg(t_data *data)
{
	int	cnt;
	int	temp;
	int	temp1;

	temp1 = data->stack2_start;
	temp = data->stack2_start;
	cnt = data->stack2_start;
	while (cnt < data->stack2_end)
	{
		if (data->stack2[temp] < data->stack2[cnt])
		{
			temp1 = temp;
			temp = cnt;
		}
		cnt++;
	}
	rev_push_utils(data, temp, temp1);
}

void	sorting(t_data *data)
{
	while (data->seg_proc != data->seg_width && data->direction == 0)
		push_median(data);
	while (data->seg_proc != data->seg_width && data->direction == 1)
		push_median1(data);
	while (data->stack2_len != 0 && data->direction == 0)
		rev_push_seg(data);
	while (data->stack2_len != 0 && data->direction == 1)
		rev_push_seg(data);
	if (data->seg_proc == data->seg_width)
		update_stuff(data);
}

void	start_sort(t_data *data)
{
	calculate_x(data);
	calculate_segment_width(data);
	sorting(data);
	sorting(data);
	sorting(data);
}
