/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:36:13 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/20 13:50:41 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	rra(t_data *data)
{
	if (data->stack1_len < 2)
		return ;
	data->stack1[data->stack1_start - 1] = data->stack1[data->stack1_end - 1];
	data->stack1[data->stack1_end - 1] = 0;
	data->stack1_start--;
	data->stack1_end--;
	ft_printf("rra\n");
	if (data->stack1_start == 1)
		array_fixer4(data);
}
