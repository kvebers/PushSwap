/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:42:58 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/18 13:17:18 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ss(t_data *data)
{
	if (data->stack1_len < 2 || data->stack2_len < 2)
		return ;
	sb(data);
	sa(data);
	ft_printf("ss\n");
}
