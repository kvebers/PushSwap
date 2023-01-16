/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:25:13 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/16 14:50:30 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_print_stacks(t_data *data)
{
	int	cnt;

	cnt = 0;
	while (cnt < data->malloc_len)
	{
		ft_printf("%i", data->stack1[cnt]);
		cnt++;
	}
	ft_printf(" ");
	cnt = 0;
	while (cnt < data->malloc_len)
	{
		ft_printf("%i", data->stack2[cnt]);
		cnt++;
	}
	ft_printf("\n");
}

int	check_sort(t_data *data)
{
	int	cnt;
	int	cnt1;

	cnt = data->stack1_start;
	if (data->stack2_len > 0)
		return (0);
	while (cnt < data->stack1_end - 1)
	{
		cnt1 = cnt + 1;
		if (data->stack1[cnt] > data->stack1[cnt1])
			return (0);
		cnt++;
	}
	return (1);
}

void	calculate_x(t_data *data)
{
	int	temp;
	int	temp1;
	int	constant;
	int	constant1;

	constant = data->argc / (data->x * 2);
	constant1 = data->argc * data->x / 2;
	temp1 = data->x * (1 + constant) * constant / 4 + constant1;
	data->x++;
	while (data->x < data->argc)
	{
		constant = data->argc / (data->x * 2);
		constant1 = data->argc * data->x / 2;
		temp = data->x * (1 + constant) * constant / 4 + constant1;
		if (temp1 > temp)
			temp1 = temp;
		else
		{
			data->x--;
			data->max_it = temp1;
			break ;
		}
		data->x++;
	}
}

void	calculate_segment_width(t_data *data)
{
	data->seg_width = data->argc / data->x;
	ft_printf("\nThere are %i elements in segment\n", data->seg_width);
	ft_printf("There are %i segments\n", data->x);
}

void	start_sort(t_data *data)
{
	calculate_x(data);
	calculate_segment_width(data);
	while (check_sort(data) == 0)
	{
		if (data->step == 10)
			break ; // remove after the test phase
		// if (data->step == 1)
		// 	pb(data);
		// if (data->step == 2)
		// 	pb(data);
		// if (data->step == 3)
		// 	rr(data);
		// if (data->step == 4)
		// 	rrr(data);
		// if (data->step == 5)
		// 	ss(data);
		// if (data->step == 6)
		// 	pa(data);
		// ft_print_stacks(data);
		data->step++;
	}
}
