#include "push_swap.h"

static int	min_pos(t_stack *a)
{
	int	i;
	int	pos;

	i = 1;
	pos = 0;
	while (i < a->size)
	{
		if (a->values[i] < a->values[pos])
			pos = i;
		i++;
	}
	return (pos);
}

static int	max_pos(t_stack *a)
{
	int	i;
	int	pos;

	i = 1;
	pos = 0;
	while (i < a->size)
	{
		if (a->values[i] > a->values[pos])
			pos = i;
		i++;
	}
	return (pos);
}

static void	sort_three(t_stack *a)
{
	int	max;

	max = max_pos(a);
	if (max == 0)
		ra(a);
	else if (max == 1)
		rra(a);
	if (a->values[0] > a->values[1])
		sa(a);
}

static void	move_min_to_b(t_stack *a, t_stack *b)
{
	int	pos;
	int	half;

	pos = min_pos(a);
	half = a->size / 2;
	while (pos > 0)
	{
		if (pos <= half)
			ra(a);
		else
			rra(a);
		pos = min_pos(a);
	}
	pb(a, b);
}

void	sort_small(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (a->values[0] > a->values[1])
			sa(a);
		return ;
	}
	while (a->size > 3)
		move_min_to_b(a, b);
	sort_three(a);
	while (b->size > 0)
		pa(a, b);
}
