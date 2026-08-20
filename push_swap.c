/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-a <malves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 16:11:18 by malves-a          #+#    #+#             */
/*   Updated: 2026/08/20 16:11:23 by malves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	data_init(t_data *data)
{
	data->stack_a.head = NULL;
	data->stack_a.tail = NULL;
	data->stack_a.size = 0;

	data->stack_b.head = NULL;
	data->stack_b.tail = NULL;
	data->stack_b.size = 0;

	data->bench = 0;
	data->total_ops = 0;
}