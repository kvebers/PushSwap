/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:02:36 by kvebers           #+#    #+#             */
/*   Updated: 2023/01/10 17:54:06 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft/libft.h"

typedef struct data
{
	int	argc;
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
int		protection4(int argc);
int		protection3(int bonus, char *argv);
int		protection2(int argc, char **argv);
int		protection1(int argc, char **argv);
int		protection(int argc, char **argv);
int		init_data(int argc, char **argv, t_data *data);
//protection1.c
int		protection6(int *stack, int argc);
int		protection5(int argc, char **argv);
//free.c
void	free_stuff(t_data *data);
//sort.c
void	start_sort(t_data *data);
int		check_sort(t_data *data);
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
