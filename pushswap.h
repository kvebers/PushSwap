/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:02:36 by kvebers           #+#    #+#             */
/*   Updated: 2023/03/27 17:22:17 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft/libft.h"

typedef struct data
{
	int	offset;
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
int		prot_max_size(t_data *data);
int		prot_atoi1(int bonus, char *argv);
int		prot_atoi(char *argv);
int		prot_chars(int argc, char **argv, int cnt, int c);
int		protection(int argc, char **argv, t_data *data);
//protection1.c
int		count_args(t_data *data, char **argv, int argc, int cnt);
int		prot_data(t_data *data, char **argv, int argc, int cnt);
int		prot_sorted(t_data *data);
//init_data.c
int		init_data(t_data *data);
int		init_medians(t_data *data);
//free.c
void	free_stuff(t_data *data);
//sort.c
void	start_sort(t_data *data);
void	start_sort1(t_data *data);
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
void	quick_sort_a(t_data *data);
int		check_medians(t_data *data);
void	quick_sort_a1(t_data *data);
//sort2.c
void	loop_sort(t_data *data, int median);
void	quick_sort_b2(t_data *data, int median);
void	quick_sort_b1(t_data *data, int median);
void	quick_sort_b(t_data *data, int median);
//sort3.c
void	start_sort2(t_data *data);
//decision.c
void	push_to_sort(t_data *data);
void	decision(t_data *data, int temp1);
//sort_small_stacks
void	stack_size_2_handle(t_data *data);
void	stack_size_3_handle(t_data *data);
void	stack_size_45_handle(t_data *data);
void	start_sort5(t_data *data);
#endif
