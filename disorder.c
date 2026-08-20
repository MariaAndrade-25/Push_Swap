
int	disorder_bp(t_stack *a)
{
	long	mistakes;
	long	pairs;
	int		i;
	int		j;

	pairs = a->size * (a->size - 1) / 2;
	if (pairs == 0)
		return (0);
	mistakes = 0;
	i = -1;
	while (++i < a->size)
	{
		j = i;
		while (++j < a->size)
		{
			if (a->values[i] > a->values[j])
				mistakes++;
		}
	}
	return ((int)((mistakes * 10000 + pairs / 2) / pairs));
}

