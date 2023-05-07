/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s2_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbordoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:47:20 by nbordoni          #+#    #+#             */
/*   Updated: 2023/03/18 11:47:23 by nbordoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rra_sort(t_push *a, int ac)
{
	int	swap;

	swap = a->stacka[ac - 1];
	ft_memcpy3(a->stacka, ac);
	a->stacka[0] = swap;
	ft_printf("rra\n");
}

void	rra2_sort(t_push *a)
{
	int	swap;
	int	swap2;

	swap = a->stacka[0];
	swap2 = a->stacka[1];
	a->stacka[0] = a->stacka[2];
	a->stacka[1] = swap;
	a->stacka[2] = swap2;
	ft_printf("rra\n");
}
