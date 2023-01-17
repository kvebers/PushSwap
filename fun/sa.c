/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:15:34 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/17 17:26:11 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	sa(t_data *data)
{
	int	temp;

	if (data->stack1_len < 2)
		return ;
	temp = data->stack1[data->stack1_start];
	data->stack1[data->stack1_start] = data->stack1[data->stack1_start + 1];
	data->stack1[data->stack1_start + 1] = temp;
	ft_printf("sa");
}
