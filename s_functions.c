/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbordoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:47:31 by nbordoni          #+#    #+#             */
/*   Updated: 2023/03/18 11:47:33 by nbordoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sa_sort(t_push *a)
{
	int	swap;

	swap = a->stacka[0];
	a->stacka[0] = a->stacka[1];
	a->stacka[1] = swap;
	ft_printf("sa\n");
}

void	sb_sort(t_push *a)
{
	int	swap;

	swap = a->stackb[0];
	a->stackb[0] = a->stackb[1];
	a->stackb[1] = swap;
	ft_printf("sb\n");
}

void	pb_sort(t_push *a, int ac)
{
	if (a->flag == -1)
		a->flag = 0;
	a->sizeb++;
	a->stackb = ft_memcpy2(a->stackb, a->sizeb, 1);
	a->stackb[0] = a->stacka[0];
	a->stacka = ft_memcpy2(a->stacka, ac, 0);
	ft_printf("pb\n");
}

void	pa_sort(t_push *a, int ac)
{
	a->flag = 42;
	a->sizeb--;
	a->stacka = ft_memcpy2(a->stacka, ac, 1);
	a->stacka[0] = a->stackb[0];
	a->stackb = ft_memcpy2(a->stackb, a->sizeb, 0);
	ft_printf("pa\n");
}

void	ra_sort(t_push *a, int ac)
{
	int	swap;
	int	i;

	i = 0;
	swap = a->stacka[i];
	while (i < ac - 1)
	{
		a->stacka[i] = a->stacka[i + 1];
		i++;
	}
	a->stacka[i] = swap;
	ft_printf("ra\n");
}
