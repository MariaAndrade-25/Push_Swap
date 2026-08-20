/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-a <malves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 15:49:13 by malves-a          #+#    #+#             */
/*   Updated: 2026/08/18 18:36:14 by malves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	num_over(long num, int sign, int digit)
{
	if (num > INT_MAX / 10)
		return (1);
	if (num == INT_MAX / 10 && digit > 7 + (sign == -1))
		return (1);
	return (0);
}

int	ft_atoi_safe(char *str, int *result)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	if (!str || !result)
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	if (str[i] == '\0')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (num_over(num, sign, str[i] - '0'))
			return (0);
		num = num * 10 + (str[i++] - '0');
	}
	if (str[i] != '\0')
		return (0);
	*result = (int)(sign * num);
	return (1);
}

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
			a->values[a->size] = value;
			a->size++;
			j++;
		}
		free_tokens(tokens);
		i++;
	}
	return (1);
}
