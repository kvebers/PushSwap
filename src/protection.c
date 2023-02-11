/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:34:15 by kvebers           #+#    #+#             */
/*   Updated: 2023/02/11 19:39:49 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

/*
Handles the maximum array capacity
*/

int	prot_max_size(t_data *data)
{
	if (data->argc > 2147483647 / 6)
	{
		ft_printf("Error\n");
		return (0);
	}
	return (1);
}

int	prot_atoi1(int bonus, char *argv)
{
	int		cnt;
	char	*max;

	if (bonus == 0)
		max = ft_strdup("2147483647");
	if (bonus == 1)
		max = ft_strdup("-2147483648");
	cnt = bonus;
	while (argv[cnt] != '\0')
	{
		if (argv[cnt] > max[cnt])
			return (free(max), 0);
		else if (argv[cnt] < max[cnt])
			return (free(max), 1);
		cnt++;
	}
	return (free(max), 1);
}

int	prot_atoi(char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (argv[0] == '-' && len > 11)
		return (0);
	if (argv[0] != '-' && len > 10)
		return (0);
	if (argv[0] == '-' && len == 11)
	{
		if (prot_atoi1(1, argv) == 0)
			return (0);
	}
	if (argv[0] != '-' && len == 10)
	{
		if (prot_atoi1(0, argv) == 0)
			return (0);
	}
	return (1);
}

int	prot_chars(int argc, char **argv, int cnt, int c)
{
	while (cnt < argc)
	{
		if (*(argv[cnt]) == '-' && *(argv[cnt] + 1) != '\0')
			c = 1;
		else
			c = 0;
		while (*(argv[cnt] + c) != '\0')
		{
			if (*(argv[cnt] + c) == ' ' || *(argv[cnt] + c) == '-')
			{
			}
			else if (ft_isdigit(*(argv[cnt] + c)) == 0)
				return (0);
			c++;
		}
		cnt++;
	}
	return (1);
}

int	protection(int argc, char **argv, t_data *data)
{
	data->argc = 0;
	if (argc == 1)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (prot_chars(argc, argv, 1, 0) == 0)
	{
		ft_printf("Error");
		return (0);
	}
	if (count_args(data, argv, argc, 1) == 0)
		return (0);
	if (prot_max_size(data) == 0)
		return (0);
	if (prot_data(data, argv, argc, 1) == 0)
	{
		ft_printf("Error\n");
		return (free(data->stack), 0);
	}
	return (1);
}
