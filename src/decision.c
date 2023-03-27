/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:54:44 by kvebers           #+#    #+#             */
/*   Updated: 2023/03/27 19:34:26 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	decision(t_data *data, int temp1)
{
 	static int	swap;

	if (temp1 == data->stack2_start && swap == 0)
		pa(data);
	else if (temp1 == data->stack2_start && swap == 1)
	{
		pa(data);
		sa(data);
		swap = 0;
	}
	else if (data->stack2[data->stack2_start] == data->stack2[temp1] - 1
		&& swap == 0)
	{
		pa (data);
		swap = 1;
	}
	else if (temp1 > data->stack2_start + data->stack2_len / 2)
		rrb(data);
	else
		rb(data);
}

void	push_to_sort(t_data *data)
{
 	int	cnt;
	int	temp1;

	cnt = data->stack2_start;
	temp1 = cnt;
	while (cnt < data->stack2_end)
	{
		if (data->stack2[cnt] > data->stack2[temp1])
			temp1 = cnt;
		cnt++;
	}
	decision(data, temp1);
}

// void	decision(t_data *data, int temp1)
// {
//  	static int	swap;
// 	static int	swap1;

// 	if (temp1 == data->stack2_start && swap == 0 && swap1 == 0)
// 		pa(data);
// 	else if (temp1 == data->stack2_start && swap == 1 && swap1 == 0)
// 	{
// 		pa(data);
// 		sa(data);
// 		swap = 0;
// 	}
// 	else if (data->stack2[data->stack2_start] == data->stack2[temp1] - 1
// 		&& swap == 0 && swap1 == 0)
// 	{
// 		pa (data);
// 		swap = 1;
// 	}
// 	else if (data->stack2[data->stack2_start] == data->stack2[temp1] - 2
// 		&& swap1 == 0)
// 	{
// 		pa (data);
// 		swap1 = 1;
// 	}
// 	else if (temp1 == data->stack2_start && swap1 == 1 && swap == 0)
// 	{
// 		pa (data);
// 		sa (data);
// 		swap1 = 0;
// 		swap = 1;
// 	}
// 	else if (temp1 == data->stack2_start && swap1 == 1 && swap == 1)
// 	{
// 		if (data->stack1[data->stack1_start] < data->stack1[data->stack1_start + 1])
// 		{
// 			pa(data);
// 			sa(data);
// 			ra(data);
// 			sa(data);
// 			rra(data);
// 		}
// 		else
// 		{
// 			pa(data);
// 			sa(data);
// 			ra(data);
// 			sa(data);
// 			rra(data);
// 			sa(data);
// 		}
// 		swap1 = 0;
// 		swap = 0;
		
// 	}
// 	else if (temp1 > data->stack2_start + data->stack2_len / 2)
// 		rrb(data);
// 	else
// 		rb(data);
// }

// void	push_to_sort(t_data *data)
// {
//  	int	cnt;
// 	int	temp1;

// 	cnt = data->stack2_start;
// 	temp1 = cnt;
// 	while (cnt < data->stack2_end)
// 	{
// 		if (data->stack2[cnt] > data->stack2[temp1])
// 			temp1 = cnt;
// 		cnt++;
// 	}
// 	decision(data, temp1);
// }
