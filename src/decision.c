/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:54:44 by kvebers           #+#    #+#             */
/*   Updated: 2023/02/09 15:50:52 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

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
	int	cnt;
	int	temp1;

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
