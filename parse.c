/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-a <malves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 16:18:59 by malves-a          #+#    #+#             */
/*   Updated: 2026/08/25 16:19:00 by malves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	word_count(char *s)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != ' ' && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == ' ')
			in_word = 0;
		s++;
	}
	return (count);
}

int	count_total_elements(int argc, char **argv)
{
	int	total;
	int	i;

	total = 0;
	i = 1;
	while (i < argc)
		total += word_count(argv[i++]);
	return (total);
}

int	ft_atoi_safe(char *str, int *result)
{
	long	num;
	int		sign;
	int		i;

	if (!str || !*str)
		return (0);
	num = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		num = num * 10 + (str[i++] - '0');
		if ((sign == 1 && num > INT_MAX)
			|| (sign == -1 && num > (long)INT_MAX + 1))
			return (0);
	}
	*result = (int)(num * sign);
	return (1);
}

int	parse_args(int argc, char **argv, t_stack *stack)
{
	char	**tokens;
	int		i;
	int		j;
	int		value;

	i = 1;
	while (i < argc)
	{
		tokens = ft_split(argv[i++], ' ');
		if (!tokens)
			return (0);
		j = 0;
		while (tokens[j])
		{
			if (!ft_atoi_safe(tokens[j++], &value))
				return (free_tokens(tokens), 0);
			if (stack->size >= stack->capacity)
				return (free_tokens(tokens), 0);
			stack->values[stack->size++] = value;
		}
		free_tokens(tokens);
	}
	return (stack->size > 0);
}
