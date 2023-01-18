/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:55:30 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/18 13:16:50 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ra(t_data *data)
{
	if (data->stack1_len < 2)
		return ;
	data->stack1[data->stack1_end] = data->stack1[data->stack1_start];
	data->stack1[data->stack1_start] = 0;
	data->stack1_start++;
	data->stack1_end++;
	ft_printf("ra\n");
	if (data->stack1_end == data->malloc_len -1)
		array_fixer1(data);
}
