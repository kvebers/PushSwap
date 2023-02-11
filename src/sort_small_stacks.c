/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:17:23 by kvebers           #+#    #+#             */
/*   Updated: 2023/02/11 22:01:39 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	stack_size_2_handle(t_data *data)
{
	sa(data);
}

void	check_if_1(t_data *data)
{
	int	cnt;
	int	boolean;

	boolean = 0;
	cnt = data->stack1_start;
	while (cnt < data->stack1_end)
	{
		if (data->stack1[cnt] == 1)
			boolean = 1;
		cnt++;
	}
	if (boolean == 0)
		return ;
	cnt = data->stack1_start;
	while (cnt < data->stack1_end)
	{
		data->stack1[cnt] = data->stack1[cnt] + 1;
		cnt++;
	}
}

void	stack_size_3_handle(t_data *data)
{
	check_if_1(data);
	if (data->stack1[data->stack1_start] == 3
		&& data->stack1[data->stack1_start + 1] == 2)
	{
		sa(data);
	}
	else if (data->stack1[data->stack1_start] == 4
		&& data->stack1[data->stack1_start + 1] == 2)
		ra(data);
	else if (data->stack1[data->stack1_start] == 4
		&& data->stack1[data->stack1_start + 1] == 3)
	{
		sa(data);
		rra(data);
	}
	else if (data->stack1[data->stack1_start] == 3
		&& data->stack1[data->stack1_start + 1] == 4)
		rra(data);
	else if (data->stack1[data->stack1_start] == 2
		&& data->stack1[data->stack1_start + 1] == 4)
	{
		sa(data);
		ra(data);
	}
}

void	stack_45_decide(t_data *data, int temp1)
{
	static int	swap;

	if (temp1 == data->stack1_start && swap == 0)
		pb(data);
	else if (temp1 == data->stack1_start && swap == 1)
	{
		pb(data);
		sb(data);
		swap = 0;
	}
	else if (data->stack1[data->stack1_start] == data->stack1[temp1] + 1
		&& swap == 0 && data->stack1_len > 3)
	{
		pb (data);
		swap = 1;
	}
	else if (temp1 > data->stack1_start + data->stack1_len / 2)
		rra(data);
	else
		ra(data);
}

void	stack_size_45_handle(t_data *data)
{
	int	cnt;
	int	temp1;

	while (data->stack1_len > 2)
	{
		cnt = data->stack1_start;
		temp1 = cnt;
		while (cnt < data->stack1_end)
		{
			if (data->stack1[cnt] < data->stack1[temp1])
				temp1 = cnt;
			cnt++;
		}
		stack_45_decide(data, temp1);
	}
	if (data->stack1[data->stack1_start] > data->stack1[data->stack1_start + 1])
		sa(data);
	while (data->stack2_len > 0)
		decision(data, data->stack2_start);
}
