/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:23:50 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/17 17:26:17 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	sb(t_data *data)
{
	int	temp;

	if (data->stack2_len < 2)
		return ;
	temp = data->stack2[data->stack2_start];
	data->stack2[data->stack2_start] = data->stack2[data->stack2_start + 1];
	data->stack2[data->stack2_start + 1] = temp;
	ft_printf("sb");
}
