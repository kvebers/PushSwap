/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:02:36 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/17 16:31:29 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft/libft.h"

typedef struct data
{
	int	x;
	int direction;
	int	seg_proc;
	int	x_done;
	int	seg_width;
	int	max_it;
	int	split_val;
	int	median;
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
	int	step;
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
//free.c
void	free_stuff(t_data *data);
//sort.c
void	start_sort(t_data *data);
//sort_utils.c
int		check_sort(t_data *data);
void	calculate_segment_width(t_data *data);
void	calculate_x(t_data *data);
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

#endif
