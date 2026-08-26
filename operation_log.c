/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_log.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-a <malves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 00:00:00 by malves-a          #+#    #+#             */
/*   Updated: 2026/08/26 00:00:00 by malves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_operation(char *operation)
{
	int	i;

	i = 0;
	while (operation[i])
	{
		write(1, &operation[i], 1);
		i++;
	}
	write(1, "\n", 1);
}