/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:43:26 by kvebers           #+#    #+#             */
/*   Updated: 2023/02/10 16:15:14 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	ft_sqrt(int argc)
{
	int	cnt;

	cnt = 0;
	while (cnt * cnt < argc)
		cnt++;
	return (cnt - 1);
}

void	start_sort2(t_data *data)
{
	int	range;
	int	cnt;

	range = ft_sqrt(data->argc) * 3 / 2;
	cnt = 1;
	while (data->stack1_len > 0)
	{
		if (data->stack1[data->stack1_start] <= cnt)
		{
			pb(data);
			rb(data);
			cnt++;
		}
		else if (data->stack1[data->stack1_start] <= cnt + range)
		{
			pb(data);
			cnt++;
		}
		else
			ra(data);
	}
	while (data->stack2_len > 0)
		push_to_sort(data);
}
