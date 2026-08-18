/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_duplicate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-a <malves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 18:12:35 by malves-a          #+#    #+#             */
/*   Updated: 2026/08/18 18:21:49 by malves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_duplicate(t_stack *stack, int value)
{
	aux	t_stack*;
	int	i;

	i = 0;

	if (!stack)
		return (0);
	while (aux[i] != '\0')
	{
		if (aux->value == value[i])
		{
			return (1);
		}
		i++;
	}
}
