/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbordoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:46:17 by nbordoni          #+#    #+#             */
/*   Updated: 2023/03/18 11:46:23 by nbordoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// ti dice la cifra piu grande quanti bit ha //
int	max_bity(t_push *a)
{
	int	max;
	int	bit_shift;

	bit_shift = 0;
	max = a->big;
	while (max >> bit_shift)
		bit_shift++;
	return (bit_shift);
}

// Radix Sort //
void	sort_big(t_push *a, int ac)
{
	int	max_bit;
	int	i;
	int	j;

	i = 0;
	max_bit = max_bity(a);
	while (i < max_bit)
	{
		j = 0;
		while (j < a->dimy)
		{
			if (((a->stack[0] >> i) & 1) == 1)
				ra_sortb(a, ac);
			else
				pb_sortb(a, --ac);
			j++;
		}
		while (a->sizeb)
			pa_sortb(a, ++ac);
		i++;
	}
}
