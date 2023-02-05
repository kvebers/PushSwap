/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:07:24 by kvebers           #+#    #+#             */
/*   Updated: 2023/02/05 11:30:20 by kvebers          ###   ########.fr       */
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
