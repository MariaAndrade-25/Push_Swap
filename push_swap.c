/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malves-a <malves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 16:11:18 by malves-a          #+#    #+#             */
/*   Updated: 2026/08/25 18:47:11 by malves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Inicializa qualquer estrutura de dados auxiliar que voce precise.
** (Caso decida usar a t_data que mencionou no prompt anterior).
*/
void	data_init(t_data *data)
{
	if (!data)
		return ;
	data->a = NULL;
	data->b = NULL;
}

/*
** Funcao principal de roteamento de ordenacao.
** Chamada pela sua main() quando is_sorted(a) for falso.
*/
void	sort_stack(t_stack *a, t_stack *b)
{
	if (!a || !b || a->size < 2)
		return ;
	if (a->size == 2)
		sa(a);
	else if (a->size <= 5)
	{
		/* Assume-se que a logica de 3 a 5 numeros esta aqui */
		ft_sort_small(a, b);
	}
	else if (a->size <= 100)
	{
		/* Geralmente usa-se chunk para 100 numeros na 42 */
		/* Substitua pelo nome exato da funcao no seu sort_chunk.c */
		ft_chunk_sort(a, b);
	}
	else
	{
		/* Radix ou Chunk otimizado para 500 numeros */
		/* Substitua pelo nome exato da funcao no seu sort_radix.c */
		ft_sort_radix(a, b);
	}
}
