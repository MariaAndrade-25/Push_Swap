/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-a <malves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 16:17:54 by malves-a          #+#    #+#             */
/*   Updated: 2026/08/25 16:17:57 by malves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	error_exit(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		total;

	if (argc < 2)
		return (0);
	total = count_total_elements(argc, argv);
	if (total <= 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	a = init_stack(total);
	b = init_stack(total);
	if (!a || !b)
		error_exit(a, b);
	if (!parse_args(argc, argv, a) || has_duplicates(a))
		error_exit(a, b);
	if (!is_sorted(a))
		sort_stack(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
