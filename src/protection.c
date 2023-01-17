/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:34:15 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/17 13:03:06 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	protection4(t_data *data)
{
	if (data->argc > 2147483647 / 2)
	{
		ft_printf("Error: This algo is not ment for handling so many inputs\n");
		return (0);
	}
	return (1);
}

int	protection3(int bonus, char *argv)
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

int	protection2(char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (argv[0] == '-' && len > 11)
		return (0);
	if (argv[0] != '-' && len > 10)
		return (0);
	if (argv[0] == '-' && len == 11)
	{
		if (protection3(1, argv) == 0)
			return (0);
	}
	if (argv[0] != '-' && len == 10)
	{
		if (protection3(0, argv) == 0)
			return (0);
	}
	return (1);
}

int	protection1(int argc, char **argv, int cnt, int c)
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
			{
				ft_printf("Error: There is a non digit in the function args\n");
				return (0);
			}
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
		ft_printf("Error: There are no arguments passed\n");
		return (0);
	}
	if (protection1(argc, argv, 1, 0) == 0)
	{
		ft_printf("Error: not allowed chars in input\n");
		return (0);
	}
	if (protection5(data, argv, argc, 1) == 0)
		return (0);
	if (protection4(data) == 0)
		return (0);
	if (protection6(data, argv, argc, 1) == 0)
	{
		ft_printf("Error: Atoi or Malloc or smt else\n");
		return (free(data->stack), 0);
	}
	return (1);
}
