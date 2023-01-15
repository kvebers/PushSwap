/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:23:54 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/15 14:36:58 by kvebers          ###   ########.fr       */
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
		return (free(data), 0);
	start_sort(data);
	free_stuff(data);
	system("leaks pushswap");
	return (0);
}
