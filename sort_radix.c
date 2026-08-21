#include "push_swap.h"

static void	sort_copy(int *copy, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (copy[i] > copy[j])
			{
				tmp = copy[i];
				copy[i] = copy[j];
				copy[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	value_rank(int *sorted, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (0);
}

static int	*sorted_values(t_stack *a)
{
	int	*copy;
	int	i;

	copy = malloc(sizeof(int) * a->size);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < a->size)
	{
		copy[i] = a->values[i];
		i++;
	}
	sort_copy(copy, a->size);
	return (copy);
}

static int	max_bits(int size)
{
	int	bits;
	int	max;

	bits = 0;
	max = size - 1;
	while (max > 0)
	{
		bits++;
		max >>= 1;
	}
	return (bits);
}

void	sort_radix(t_stack *a, t_stack *b)
{
	int	*sorted;
	int	size;
	int	bits;
	int	bit;
	int	count;

	size = a->size;
	sorted = sorted_values(a);
	if (!sorted)
		return ;
	bits = max_bits(size);
	bit = 0;
	while (bit < bits)
	{
		count = a->size;
		while (count-- > 0)
		{
			if ((value_rank(sorted, size, a->values[0]) >> bit) & 1)
				ra(a);
			else
				pb(a, b);
		}
		while (b->size > 0)
			pa(a, b);
		bit++;
	}
	free(sorted);
}
