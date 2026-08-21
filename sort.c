#include "push_swap.h"

void	sort_small(t_stack *a, t_stack *b);
void	sort_radix(t_stack *a, t_stack *b);

void	sort_stack(t_stack *a, t_stack *b)
{
	if (a->size <= 5)
		sort_small(a, b);
	else
		sort_radix(a, b);
}
