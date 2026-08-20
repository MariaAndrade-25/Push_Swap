/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-a <malves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 16:19:36 by malves-a          #+#    #+#             */
/*   Updated: 2026/08/20 16:22:23 by malves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	disorder_bp(t_stack *a)
{
	long	mistakes;
	long	pairs;
	int		i;
	int		j;

	pairs = a->size * (a->size - 1) / 2;
	if (pairs == 0)
		return (0);
	mistakes = 0;
	i = -1;
	while (++i < a->size)
	{
		j = i;
		while (++j < a->size)
		{
			if (a->values[i] > a->values[j])
				mistakes++;
		}
	}
	return ((int)((mistakes * 10000 + pairs / 2) / pairs));
}

int	compute_disorder(stack *a)
{
	int		mistakes;
	int		total_pairs;

	mistakes = 0;
	total_pairs = 0;
	while(size(a)-1)
}
