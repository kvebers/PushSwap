/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:34:15 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/10 14:55:42 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	protection4(int argc)
{
	if (argc > 2147483647 / 2)
	{
		ft_printf("Error: This algo is not ment for handling so many inputs");
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

int	protection2(int argc, char **argv)
{
	int	cnt;
	int	len;

	cnt = 1;
	while (cnt < argc)
	{
		len = ft_strlen(argv[cnt]);
		if (*(argv[cnt]) == '-' && len > 11)
			return (0);
		if (*(argv[cnt]) != '-' && len > 10)
			return (0);
		if (*(argv[cnt]) == '-' && len == 11)
		{
			if (protection3(1, argv[cnt]) == 0)
				return (0);
		}
		if (*(argv[cnt]) != '-' && len == 10)
		{
			if (protection3(0, argv[cnt]) == 0)
				return (0);
		}
		cnt++;
	}
	return (1);
}

int	protection1(int argc, char **argv)
{
	int	cnt;
	int	cnt1;

	cnt = 1;
	while (cnt < argc)
	{
		if (*(argv[cnt]) == '-' && *(argv[cnt] + 1) != '\0')
			cnt1 = 1;
		else
			cnt1 = 0;
		while (*(argv[cnt] + cnt1) != '\0')
		{
			if (ft_isdigit(*(argv[cnt] + cnt1)) == 0)
			{
				ft_printf("Error: There is a non digit in the function args");
				return (0);
			}
			cnt1++;
		}
		cnt++;
	}
	return (1);
}

int	protection(int argc, char **argv)
{
	if (protection4(argc) == 0)
		return (0);
	if (argc == 1)
	{
		ft_printf("Error: There are no arguments passed");
		return (0);
	}
	if (protection1(argc, argv) == 0)
		return (0);
	if (protection2(argc, argv) == 0)
	{
		ft_printf("Error: Int out of bounds");
		return (0);
	}
	if (protection5(argc, argv) == 0)
	{
		ft_printf("Error: 2 of the same array or smt else");
		return (0);
	}
	return (1);
}
