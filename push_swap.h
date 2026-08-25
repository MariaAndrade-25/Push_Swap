/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-a <malves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 15:24:33 by mtomanar          #+#    #+#             */
/*   Updated: 2026/08/25 16:12:50 by malves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int		values;
	long	size;
	int		capacity;
}	t_stack;

int			ft_haschunk(t_stack *stack_a, int start, int end);
int			ft_sqrt(int n);
int			find_maxindex(t_stack *stack_a);
int			find_minindex(t_stack *stack_a);
void		ft_push_max(t_stack *stack_a, t_stack *stack_b);
void		sort_top(t_stack *stack_a);
void		sort_bottom(t_stack *stack_a);
void		ft_swap(t_stack *stack);
void		sa(t_stack *stack_a);
void		sb(t_stack *stack_b);
void		ss(t_stack *stack_a, t_stack *stack_b);
void		ft_push(t_stack *from, t_stack *to);
void		pa(t_stack *stack_a, t_stack *stack_b);
void		pb(t_stack *stack_a, t_stack *stack_b);
void		ft_reverse(t_stack *stack);
void		rra(t_stack *stack_a);
void		rrb(t_stack *stack_b);
void		rrr(t_stack *stack_a, t_stack *stack_b);
void		ft_rotate(t_stack *stack);
void		ra(t_stack *stack_a);
void		rb(t_stack *stack_b);
void		rr(t_stack *stack_a, t_stack *stack_b);
static void	ft_rotate_max(t_stack *stack_b, int max_index);
static void	ft_process_chunk(t_stack *stack_a, t_stack *stack_b,
				int start, int end);

#endif
