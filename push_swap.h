/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-a <malves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 15:49:23 by malves-a          #+#    #+#             */
/*   Updated: 2026/08/20 18:10:45 by malves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>

typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strategy;

typedef struct s_config
{
	int			bench;
	t_strategy	strategy;
}	t_config;

typedef struct s_stack
{
	int		*values;
	long	size;
	int		capacity;
}	t_stack;

/* Parsing functions */
int		parse_args(int argc, char **argv, t_stack *a);
int		parse_token(char *token, t_stack *a);
void	free_tokens(char **tokens);
int		ft_atoi_safe(char *str, int *result);
int		count_total_elements(int argc, char **argv);
char	**ft_split(char const *s, char c);

/* Stack initialization */
t_stack	*init_stack_a(int argc, char **argv);
t_stack	*init_stack_b(int capacity);
void	free_stack(t_stack *stack);

/* Stack validation */
int		is_sorted(t_stack *a);
int		has_duplicates(t_stack *a);

/* Operations */
void	ft_swap(t_stack *stack);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);

void	ft_push(t_stack *from, t_stack *to);
void	ft_pa(t_stack *stack_a, t_stack *stack_b);
void	ft_pb(t_stack *stack_a, t_stack *stack_b);

void	ft_rotate(t_stack *stack);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);

void	ft_reverse(t_stack *stack);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

/* Sorting */
void	sort_dispatch(t_stack *a, t_stack *b);

#endif
