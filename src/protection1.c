/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protection1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:33:53 by kvebers           #+#    #+#             */
/*   Updated: 2023/02/11 20:53:50 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	prot_blanks(char *argv)
{
	int	cnt;
	int	cnt1;

	cnt = 0;
	cnt1 = 0;
	while (cnt1 < 10)
	{
		if (ft_strchr(argv, cnt1 + '0') == NULL)
		{
			cnt++;
		}
		cnt1++;
	}
	if (cnt == 10)
		return (0);
	else
		return (1);
}

int	count_args(t_data *data, char **argv, int argc, int cnt)
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

int	prot_data1(t_data *data, char *argv, int cnt)
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
		if (prot_atoi(dest[cnt1]) == 1 && ret_val != 0)
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

int	prot_data(t_data *data, char **argv, int argc, int cnt)
{
	int	cnt1;
	int	holder;

	cnt1 = 0;
	data->stack = malloc(sizeof(int) * (data->argc + 1));
	while (cnt < argc)
	{
		if (prot_blanks(argv[cnt]) == 1 && ft_strchr(argv[cnt], ' ') == NULL
			&& prot_atoi(argv[cnt]) == 1)
		{
			data->stack[cnt1] = ft_atoi(argv[cnt]);
			cnt1++;
		}
		else if (prot_blanks(argv[cnt]) == 1)
		{
			holder = prot_data1(data, argv[cnt], cnt1);
			if (holder == 0)
				return (0);
			cnt1 = cnt1 + holder;
		}
		else
			return (0);
		cnt++;
	}
	return (1);
}

int	prot_sorted(t_data *data)
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
				ft_printf("Error\n");
				return (0);
			}
			cnt2++;
		}
		cnt1++;
	}
	return (1);
}
