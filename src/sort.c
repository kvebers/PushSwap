/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:25:13 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/10 16:12:59 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	check_sort(t_data *data)
{
	int	cnt;
	int	cnt1;

	cnt = data->stack1_start;
	if (data->stack2_len > 0)
		return (0);
	while (cnt < data->stack1_end - 1)
	{
		cnt1 = cnt + 1;
		if (data->stack1[cnt] > data->stack1[cnt1])
			return (0);
		cnt++;
	}
	return (1);
}

void	start_sort(t_data *data)
{
	while (check_sort(data) == 0)
	{
		data->step++;
		if(data->step == 10)
			break; // remove after the test phase
	}
}
