/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:51:58 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/25 12:48:25 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	rrr(t_data *data)
{
	if (data->stack1_len < 2 && data->stack2_len < 2)
		return ;
	rra(data);
	rrb(data);
	ft_printf("rrr\n");
}
