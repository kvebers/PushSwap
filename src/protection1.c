/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protection1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:33:53 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/17 13:02:42 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	protection5(t_data *data, char **argv, int argc, int cnt)
{
	int		cnt1;
	char	**dest;

	while (cnt < argc)
	{
		cnt1 = 0;
		if (ft_strchr(argv[cnt], ' ') != NULL)
		{
			dest = ft_split(argv[cnt], ' ');
			if (dest == NULL)
				return (0);
			while (dest[cnt1] != NULL)
			{
				free(dest[cnt1]);
				cnt1++;
				data->argc++;
			}
			free(dest);
		}
		else
			data->argc++;
		cnt++;
	}
	return (1);
}

int	protection7(t_data *data, char *argv, int cnt)
{
	char	**dest;
	int		cnt1;
	int		ret_val;

	cnt1 = 0;
	ret_val = 1;
	dest = ft_split(argv, ' ');
	if (dest == NULL)
		return (0);
	while (dest[cnt1] != NULL)
	{
		if (protection2(dest[cnt1]) == 1 && ret_val != 0)
			ret_val = cnt1 + 1;
		else
			ret_val = 0;
		data->stack[cnt] = ft_atoi(dest[cnt1]);
		free(dest[cnt1]);
		cnt1++;
		cnt++;
	}
	return (free(dest), ret_val);
}

int	protection6(t_data *data, char **argv, int argc, int cnt)
{
	int	cnt1;
	int	holder;

	cnt1 = 0;
	data->stack = malloc(sizeof(int) * (data->argc + 1));
	while (cnt < argc)
	{
		if (ft_strchr(argv[cnt], ' ') == NULL && protection2(argv[cnt]) == 1)
		{
			data->stack[cnt1] = ft_atoi(argv[cnt]);
			cnt1++;
		}
		else
		{
			holder = protection7(data, argv[cnt], cnt1);
			if (holder == 0)
				return (0);
			cnt1 = cnt1 + holder;
		}
		cnt++;
	}
	return (1);
}

int	protection8(t_data *data)
{
	int	cnt1;
	int	cnt2;

	cnt1 = 0;
	while (cnt1 < data->argc)
	{
		cnt2 = cnt1 + 1;
		while (cnt2 < data->argc)
		{
			if (data->stack[cnt2] == data->stack[cnt1])
			{
				ft_printf("Error: 2 of the same element in the array\n");
				return (0);
			}
			cnt2++;
		}
		cnt1++;
	}
	return (1);
}