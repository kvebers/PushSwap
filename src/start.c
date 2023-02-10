/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:23:54 by kvebers           #+#    #+#             */
/*   Updated: 2023/02/10 14:47:39 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (0);
	if (protection(argc, argv, data) == 0)
		return (free(data), 0);
	if (protection8(data) == 0)
		return (free(data->stack), free(data), 0);
	if (init_data(data) == 0)
		return (free(data), free(data->stack), 0);
	if (data->argc == 2 && check_sort(data) == 0)
		stack_size_2_handle(data);
	else if (data->argc == 3 && check_sort(data) == 0)
		stack_size_3_handle(data);
	else if (data->argc < 20 && check_sort(data) == 0)
		stack_size_45_handle(data);
	else if (check_sort(data) == 0 && data->argc <= 200)
		start_sort1(data);
	else if (check_sort(data) == 0 && data->stack1[data->stack1_start] % 2 == 0)
		start_sort2(data);
	else if (check_sort(data) == 0 && data->stack1[data->stack1_start] % 2 == 1)
		start_sort(data);
	free_stuff(data);
	return (0);
}
