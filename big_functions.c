/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbordoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:47:55 by nbordoni          #+#    #+#             */
/*   Updated: 2023/03/18 11:47:58 by nbordoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	pb_sortb(t_push *a, int ac)
{
	if (a->flag == -1)
		a->flag = 0;
	a->sizeb++;
	a->stackb = ft_memcpy2(a->stackb, a->sizeb, 1);
	a->stackb[0] = a->stack[0];
	a->stack = ft_memcpy2(a->stack, ac, 0);
	ft_printf("pb\n");
}

void	pa_sortb(t_push *a, int ac)
{
	a->sizeb--;
	a->stack = ft_memcpy2(a->stack, ac, 1);
	a->stack[0] = a->stackb[0];
	a->stackb = ft_memcpy2(a->stackb, a->sizeb, 0);
	ft_printf("pa\n");
}

void	ra_sortb(t_push *a, int ac)
{
	int	swap;
	int	i;

	i = 0;
	swap = a->stack[i];
	while (i < ac - 1)
	{
		a->stack[i] = a->stack[i + 1];
		i++;
	}
	a->stack[i] = swap;
	ft_printf("ra\n");
}
