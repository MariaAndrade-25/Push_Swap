#include "push_swap.h"

static void	push(t_stack *from, t_stack *to)
{
	int	value;
	int	i;

	if (from->size == 0 || to->size >= to->capacity)
		return ;
	value = from->values[0];
	i = 0;
	while (i + 1 < from->size)
	{
		from->values[i] = from->values[i + 1];
		i++;
	}
	i = to->size;
	while (i > 0)
	{
		to->values[i] = to->values[i - 1];
		i--;
	}
	to->values[0] = value;
	from->size--;
	to->size++;
}

void	pa(t_stack *a, t_stack *b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
