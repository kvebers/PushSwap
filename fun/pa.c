/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:31:32 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/17 17:25:32 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	pa(t_data *data)
{
	if (data->stack2_len < 1)
		return ;
	data->stack1_start--;
	data->stack1[data->stack1_start] = data->stack2[data->stack2_start];
	data->stack2[data->stack2_start] = 0;
	data->stack2_start++;
	data->stack1_len++;
	data->stack2_len--;
	ft_printf("pa");
}
