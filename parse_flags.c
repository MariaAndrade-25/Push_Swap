/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-a <malves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 15:49:08 by malves-a          #+#    #+#             */
/*   Updated: 2026/08/20 18:45:29 by malves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_strategy	parse_strategy_flag(const char *flag)
{
	if (ft_strcmp(flag, "--simple") == 0)
		return (SIMPLE);
	if (ft_strcmp(flag, "--medium") == 0)
		return (MEDIUM);
	if (ft_strcmp(flag, "--complex") == 0)
		return (COMPLEX);
	if (ft_strcmp(flag, "--adaptive") == 0)
		return (ADAPTIVE);
	return (-1);
}

int	parse_config(int argc, char **argv, t_config *config)
{
	int	i;

	if (!config)
		return (-1);
	config->strategy = ADAPTIVE;
	config->bench = 0;
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] != '-')
			break ;
		if (ft_strcmp(argv[i++], "--bench") == 0)
			config->bench = 1;
		else if (parse_strategy_flag(argv[i++]) != -1)
			config->strategy = parse_strategy_flag(argv[i]);
	}
	else
		return (-1);
}
