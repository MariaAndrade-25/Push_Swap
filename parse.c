/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-a <malves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 16:18:59 by malves-a          #+#    #+#             */
/*   Updated: 2026/08/25 17:58:29 by malves-a         ###   ########.fr       */
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
		if (*s != ' ' && in_word == 0)
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
	{
		total += word_count(argv[i]);
		i++;
	}
	return (total);
}

int	ft_atoi_safe(char *str, int *result)
{
	long	num;
	int		sign;

	if (!str || !*str)
		return (0);
	num = 0;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		num = (num * 10) + (*str - '0');
		if (num > (long)INT_MAX + (sign == -1))
			return (0);
		str++;
	}
	*result = (int)(num * sign);
	return (1);
}

static int	process_tokens(char **tokens, t_stack *stack)
{
	int	j;
	int	value;

	j = 0;
	while (tokens[j])
	{
		if (!ft_atoi_safe(tokens[j], &value)
			|| stack->size >= stack->capacity)
		{
			free_tokens(tokens);
			return (0);
		}
		stack->values[stack->size++] = value;
		j++;
	}
	free_tokens(tokens);
	return (1);
}

int	parse_args(int argc, char **argv, t_stack *stack)
{
	char	**tokens;
	int		i;

	i = 1;
	while (i < argc)
	{
		tokens = ft_split(argv[i], ' ');
		if (!tokens)
			return (0);
		if (!process_tokens(tokens, stack))
			return (0);
		i++;
	}
	return (stack->size > 0);
}
