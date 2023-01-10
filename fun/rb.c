/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:32:02 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/10 17:55:52 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	rb(t_data *data)
{
	if (data->stack2_len < 2)
		return ;
	data->stack2[data->stack2_end] = data->stack2[data->stack2_start];
	data->stack2[data->stack2_start] = 0;
	data->stack2_start++;
	data->stack2_end++;
}

