/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-a <malves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 15:49:32 by malves-a          #+#    #+#             */
/*   Updated: 2026/08/18 16:46:08 by malves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack_a(int argc, char **argv)
{
	t_stack	*stack;
	int		total_elements;

	total_elements = count_total_elements(argc, argv);
	if (total_elements <= 0)
		return (NULL);
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->values = malloc(sizeof(int) * total_elements);
	if (!stack->values)
	{
		free(stack);
		return (NULL);
	}
	stack->size = 0;
	stack->capacity = total_elements;
	return (stack);
}

t_stack	*init_stack_b(int capacity)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->values = malloc(sizeof(int) * capacity);
	if (!stack->values)
	{
		free(stack);
		return (NULL);
	}
	stack->size = 0;
	stack->capacity = capacity;
	return (stack);
}

void	free_stack(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->values)
		free(stack->values);
	free(stack);
}
