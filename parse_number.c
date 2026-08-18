/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-a <malves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 15:49:13 by malves-a          #+#    #+#             */
/*   Updated: 2026/08/18 15:49:14 by malves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int is_valid_number(char *str)
{
    int i;
    i = 0;

    if (!str)
        return (0);
    if (str[i] == '-' || str[i] == '+')
          i++;
    if (str[i] == '\0')
        return (0);
    while (str[i] >= '0' && str[i] <= '9')
        i++;
    if (str[i] == '\0')
        {
            return (1);
        }
    return (0);
}

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
