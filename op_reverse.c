/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-a <malves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 17:41:53 by mtomanar          #+#    #+#             */
/*   Updated: 2026/08/20 16:09:45 by malves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse(t_stack *stack)
{
	int	temp;
	int	size; 
	int	i;

	if (!stack || stack->size <= 1)
		return ;

	size = stack->size - 1;
	i = size;
	temp = stack->values[size];
	while (i > 0)
	{
		stack->values[i] = stack->values[i - 1];
		i--;
	}
	stack->values[0] = temp;
}

void	rra(t_stack *stack_a)
{
	ft_reverse(stack_a);
}

void	rrb(t_stack *stack_b)
{
	ft_reverse(stack_b);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}

