/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:45:33 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/20 13:49:42 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	pb(t_data *data)
{
	if (data->stack1_len < 1)
		return ;
	data->stack2_start--;
	data->stack2[data->stack2_start] = data->stack1[data->stack1_start];
	data->stack1[data->stack1_start] = 0;
	data->stack1_start++;
	data->stack2_len++;
	data->stack1_len--;
	ft_printf("pb\n");
	if (data->stack1_start == 1)
		array_fixer4(data);
}
