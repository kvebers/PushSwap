/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:50:55 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/17 17:25:59 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	rrb(t_data *data)
{
	if (data->stack2_len < 2)
		return ;
	data->stack2[data->stack2_start - 1] = data->stack2[data->stack2_end - 1];
	data->stack2[data->stack2_end - 1] = 0;
	data->stack2_start--;
	data->stack2_end--;
	ft_printf("rrb");
}