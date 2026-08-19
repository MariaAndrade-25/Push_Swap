/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-a <malves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 15:49:08 by malves-a          #+#    #+#             */
/*   Updated: 2026/08/18 15:51:41 by malves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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

static int	store_token(char *token, t_stack *a)
{
	int	value;

	if (!ft_atoi_safe(token, &value))
		return (0);
	if (a->size >= a->capacity)
		return (0);
	a->values[a->size] = value;
	a->size++;
	return (1);
}

int	parse_flag(int argc, char **argv, t_stack *a)
{
	int		i;
	int		j;
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
			if (!store_token(tokens[j], a))
			{
				free_tokens(tokens);
				return (0);
			}
			j++;
		}
		free_tokens(tokens);
		i++;
	}
	return (1);
}
