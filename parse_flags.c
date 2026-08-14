#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int	parse_flag(int argc, char **argv)
{
	int		i;
	int		j;
	int		value;
	char	**tokens;

	if (!argv)
		return (0);

	i = 1;
	while (argv[i])
	{
		tokens = ft_split(argv[i], ' ');
		if (!tokens)
			return (0);

		j = 0;
		while (tokens[j])
		{
			if (is_valid_number(tokens[j]) == 0)
				return (0);

			if (ft_atoi_safe(tokens[j], &value) == 0)
				return (0);

			j++;
		}

		// aqui depois você vai liberar tokens

		i++;
	}
	return (1);
}
