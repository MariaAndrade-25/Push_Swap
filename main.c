int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = init_stack_a(argc, argv);
	if (!a || !parse_flag(argc, argv, a))
		return (write(2, "Error\n", 6), 1);
	if (has_duplicates(a))
		return (write(2, "Error\n", 6), free_stack(a), 1);
	if (is_sorted(a))
		return (free_stack(a), 0);
	b = init_stack_b(a->capacity);
	sort_dispatch(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
