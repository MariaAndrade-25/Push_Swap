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
