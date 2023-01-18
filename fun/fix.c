/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:02:11 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/18 12:08:07 by kvebers          ###   ########.fr       */
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
