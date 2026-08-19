/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-a <malves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 15:49:23 by malves-a          #+#    #+#             */
/*   Updated: 2026/08/18 15:49:24 by malves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int	*values;
	int	size;
	int	capacity;
}	t_stack;

int		parse_flag(int argc, char **argv, t_stack *a);
void	free_tokens(char **tokens);
t_stack	*init_stack_a(int argc, char **argv);
t_stack	*init_stack_b(int capacity);
void	free_stack(t_stack *stack);

#endif
