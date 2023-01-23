/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:02:11 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/20 15:19:53 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	array_fixer1(t_data *data)
{
	int	cnt;
	int	temp;

	cnt = 0;
	while (cnt < data->stack1_len + 1)
	{
		temp = data->malloc_len / 4 + cnt;
		data->stack1[temp] = data->stack1[data->stack1_start + cnt];
		data->stack1[data->stack1_start + cnt] = 0;
		cnt++;
	}
	data->stack1_start = data->malloc_len / 4;
	data->stack1_end = temp;
}

void	array_fixer2(t_data *data)
{
	int	cnt;
	int	temp;

	cnt = 0;
	while (cnt < data->stack2_len + 1)
	{
		temp = data->malloc_len / 4 + cnt;
		data->stack2[temp] = data->stack2[data->stack2_start + cnt];
		data->stack2[data->stack2_start + cnt] = 0;
		cnt++;
	}
	data->stack2_start = data->malloc_len / 4;
	data->stack2_end = temp;
}

void	array_fixer3(t_data *data)
{
	int	cnt;
	int	temp;

	cnt = 1;
	while (cnt < data->stack2_len + 1)
	{
		if (data->malloc_len < 8)
			temp = 3 - cnt;
		else
			temp = data->malloc_len / 4 * 3 - cnt;
		data->stack2[temp] = data->stack2[data->stack2_end - cnt];
		data->stack2[data->stack2_end - cnt] = 0;
		cnt++;
	}
	data->stack2_start = temp;
	data->stack2_end = data->malloc_len / 4 * 3;
}

void	array_fixer4(t_data *data)
{
	int	cnt;
	int	temp;

	cnt = 1;
	while (cnt < data->stack1_len + 1)
	{
		if (data->malloc_len < 8)
			temp = 3 - cnt;
		else
			temp = data->malloc_len / 4 * 3 - cnt;
		data->stack1[temp] = data->stack1[data->stack1_end - cnt];
		data->stack1[data->stack1_end - cnt] = 0;
		cnt++;
	}
	data->stack1_start = temp;
	data->stack1_end = data->malloc_len / 4 * 3;
}
