/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:25:13 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/17 18:08:40 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	push_median(t_data *data)
{
	int cnt;
	int cnt1;
	int sum;

	cnt = data->stack1_start;
	cnt1 = data->stack1_start;
	sum = 0;
	while (cnt < data->stack1_end)
	{
		if (data->stack1[cnt1] > data->stack[cnt])
			sum++;
		cnt++;
	}
	ft_printf("Width: %i", data->seg_width);
	ft_printf("Sum: %i\n", sum);
	if (sum > data->argc - data->seg_width * (data->x_done + 1 - data->seg_proc)
		&& sum <= data->argc - data->seg_width * data->x_done - data->seg_proc)
	{
		pb(data);
		data->seg_proc++;
	}
	else if (data->direction == 0)
		ra(data);
	else if (data->direction == 1)
		rra(data);
}

void	sorting(t_data *data)
{
	// while (check_sort(data) == 0)
	// {
	ft_printf("x %i\n",data->x);
	ft_print_stacks(data);
	ft_printf("\n");
	while (data->seg_proc != data->seg_width)
	{
	push_median(data);
	ft_printf("\n");
	ft_print_stacks(data);
	}	
}

void	start_sort(t_data *data)
{
	calculate_x(data);
	calculate_segment_width(data);
	sorting(data);
}
