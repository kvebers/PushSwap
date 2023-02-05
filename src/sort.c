/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:25:13 by kvebers           #+#    #+#             */
/*   Updated: 2023/02/05 16:56:04 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	switch_form(t_data *data)
{
	int	range;

	range = data->argc / 100;
	while (data->stack1_len > 0)
	{
		if (data->stack1[data->stack1_start] < range)
		{
			range++;
			pb(data);
			rb(data);
		}
		else
		{
			range++;
			pb(data);
		}
	}
}

void	decision(t_data *data, int temp1)
{
	static int	swap;

	if (temp1 == data->stack2_start && swap == 0)
		pa(data);
	else if (temp1 == data->stack2_start && swap == 1)
	{
		pa(data);
		sa(data);
		swap = 0;
	}
	else if (data->stack2[data->stack2_start] == data->stack2[temp1] - 1
		&& swap == 0)
	{
		pa (data);
		swap = 1;
	}
	else if (temp1 > data->stack2_start + data->stack2_len / 2)
		rrb(data);
	else
		rb(data);
}

void	push_to_sort(t_data *data)
{
	int			cnt;
	int			temp1;

	cnt = data->stack2_start;
	temp1 = cnt;
	while (cnt < data->stack2_end)
	{
		if (data->stack2[cnt] > data->stack2[temp1])
			temp1 = cnt;
		cnt++;
	}
	decision(data, temp1);
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
	while (data->stack2_len >= data->argc / 8 - 1)
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
