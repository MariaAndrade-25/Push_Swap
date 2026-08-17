
#include "push_swap.h"

void	free_tokens(char **tokens)
{
	int	i;

	if (!tokens)
		return ;
	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

int	parse_flag(int argc, char **argv, t_stack *a)
{
	int		i;
	int		j;
	int		value;
	char	**tokens;

	i = 1;
	while (i < argc)
	{
		tokens = ft_split(argv[i], ' ');
		if (!tokens)
			return (0);
		j = 0;
		while (tokens[j])
		{
			if (is_valid_number(tokens[j]) == 0
				|| ft_atoi_safe(tokens[j], &value) == 0)
			{
				free_tokens(tokens);
				return (0);
			}
			// Aqui você insere o valor na sua stack A
			a->values[a->size] = value;
			a->size++;
			j++;
		}
		free_tokens(tokens);
		i++;
	}
	return (1);
}