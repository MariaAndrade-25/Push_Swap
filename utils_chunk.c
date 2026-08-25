/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_chunk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-a <malves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 15:32:19 by mtomanar          #+#    #+#             */
/*   Updated: 2026/08/25 16:10:21 by malves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_stack *stack_a, int value)
{
	int	index;
	int	i;

	i = 0;
	index = 0;
	while (i < stack_a->size)
	{
		if (stack_a->values[i] < value)
			index++;
		i++;
	}
	return (index);
}

int	ft_haschunk(t_stack *stack_a, int start, int end)
{
	int	i;

	i = 0;
	while (i < stack_a->size)
	{
		if (stack_a->values[i] >= start && stack_a->values[i] < end)
			return (1);
		i++;
	}
	return (0);
}

void	ft_chunk_index(t_stack *stack_a)
{
	int	*indexes;
	int	i;

	i = 0;
	indexes = malloc(sizeof(int) * stack_a->size);
	if (!indexes)
		return ;
	while (i < stack_a->size)
	{
		indexes[i] = get_index(stack_a, stack_a->values[i]);
		i++;
	}
	i = 0;
	while (i < stack_a->size)
	{
		stack_a ->values[i] = indexes[i];
		i++;
	}
	free(indexes);
}
