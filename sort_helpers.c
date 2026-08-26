/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-a <malves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 00:00:00 by malves-a          #+#    #+#             */
/*   Updated: 2026/08/26 00:00:00 by malves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack_a)
{
	if (is_sorted(stack_a) == 1)
		return ;
	sa(stack_a);
}

void	sort_three(t_stack *stack_a)
{
	sort_bottom(stack_a);
	if (is_sorted(stack_a) == 1)
		return ;
	sort_two(stack_a);
}