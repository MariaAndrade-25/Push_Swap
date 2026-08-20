/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-a <malves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:20:41 by mtomanar          #+#    #+#             */
/*   Updated: 2026/08/20 16:09:51 by malves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack *stack)
{
	int	temp;
	int	i;

	if (!stack || stack->size <= 1)
		return ;
	temp = stack->values[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->values[i] = stack->values[i + 1];
		i++;
	}
	stack->values[i] = temp;
}

void	ra(t_stack *stack_a)
{
	ft_rotate(stack_a);
}

void	rb(t_stack *stack_b)
{
	ft_rotate(stack_b);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}
