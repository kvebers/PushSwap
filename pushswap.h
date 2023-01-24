/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:02:36 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/24 10:05:18 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft/libft.h"

typedef struct data
{
	int offset;
	int	seg_width;
	int	median;
	int	median1;
	int	median2;
	int	argc;
	int	*stack;
	int	*stack1;
	int	*stack2;
	int	stack1_len;
	int	stack2_len;
	int	stack1_start;
	int	stack2_start;
	int	stack1_end;
	int	stack2_end;
	int	malloc_len;
}	t_data;

//protection.c
int		protection4(t_data *data);
int		protection3(int bonus, char *argv);
int		protection2(char *argv);
int		protection1(int argc, char **argv, int cnt, int c);
int		protection(int argc, char **argv, t_data *data);
//protection1.c
int		protection5(t_data *data, char **argv, int argc, int cnt);
int		protection6(t_data *data, char **argv, int argc, int cnt);
int		protection8(t_data *data);
//init_data.c
int		init_data(t_data *data);
int		init_medians(t_data *data);
//free.c
void	free_stuff(t_data *data);
//sort.c
void	start_sort(t_data *data);
//sort_utils.c
int		check_sort(t_data *data);
void	ft_print_stacks(t_data *data);
//fun folder
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	pa(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	pb(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);
void	rr(t_data *data);
//fix.c
void	array_fixer1(t_data *data);
void	array_fixer2(t_data *data);
void	array_fixer3(t_data *data);
void	array_fixer4(t_data *data);
//sort1.c
void	quick_sort_b(t_data *data, int offset);
void	quick_sort_b1(t_data *data, int offset);
void	quick_sort_a(t_data *data);
int		check_medians(t_data *data);
void	quick_sort_a1(t_data *data);

#endif
