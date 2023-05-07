/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbordoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:46:33 by nbordoni          #+#    #+#             */
/*   Updated: 2023/03/18 11:46:36 by nbordoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	bigy(t_push *ar, int *a, int ac)
{
	int	i;
	int	big;

	i = 0;
	big = a[i];
	while (i < ac)
	{
		if (a[i] > big)
		{
			big = a[i];
			ar->pos = i;
		}
		i++;
	}
	return (big);
}

void	sort_small_3(t_push *a, int ac)
{
	if (a->dimy == 5 && !a->x2)
		a->x2 = 1;
	if (a->dimy == 5 && !a->x)
		a->x = 1;
	if (sort_checking(a->stacka, ac, a))
	{
		if (a->stacka[0] == a->big)
			ra_sort(a, ac);
		else if (a->stacka[1] == a->big && a->stacka[0] > a->stacka[2])
		{
			rra2_sort (a);
			return ;
		}
		else
			sa_sort(a);
		sort_small_3(a, ac);
	}
}

void	sort_5(t_push *a, int ac)
{
	if (sort_checking(a->stacka, ac, a))
	{
		if (ac == 3 && !a->x && !(a->stacka[0] < a->stacka[1]
				&& a->stacka[1] < a->stacka[2]))
		{
			sort_small_3(a, ac);
			a->x2 = 0;
			if (a->stacka[0] < a->stackb[0] && a->stacka[0] < a->stackb[1])
				pb_sort(a, --ac);
		}
		if (a->stacka[0] == a->big && !a->x)
			ra_sort(a, ac);
		else if ((a->stacka[0] == a->big2 || a->stacka[0] == a->big3) && !a->x)
			ra_sort(a, ac);
		else if ((a->stacka[0] > a->stacka[1] && !a->x))
			sa_sort(a);
		else if (a->sizeb >= 2 && a->stackb[0] < a->stackb[1])
			sb_sort(a);
		else if (!a->x && a->stacka[0] < a->stacka[1] && a->flag != 42
			&& ac > 3)
			pb_sort(a, --ac);
		else
			pa_sort(a, ++ac);
		sort_5(a, ac);
	}
}

void	sort_small_4_5(t_push *a, int ac)
{
	if (sort_checking(a->stacka, ac, a) && a->dimy != 5)
	{
		if (a->stacka[0] == a->big)
			ra_sort(a, ac);
		else if (a->stacka[0] > a->stacka[1])
			sa_sort(a);
		else if (a->sizeb >= 2 && a->stackb[0] < a->stackb[1])
			sb_sort(a);
		else if (a->stacka[0] < a->stacka[1] && a->flag != 42 && ac > 2)
			pb_sort(a, --ac);
		else
			pa_sort(a, ++ac);
		sort_small_4_5(a, ac);
	}
	else if (a->dimy == 5)
	{
		bigy5(a, a->stacka, ac);
		bigy5(a, a->stacka, ac);
		sort_5(a, ac);
	}
}

void	push_core(t_push *a, int ac)
{
	if (sort_checking(a->stacka, ac, a))
	{
		a->big = bigy(a, a->stacka, ac);
		a->dimy = ac;
		fill_0(a->stackb, ac);
		if (ac <= 3)
			sort_small_3(a, ac);
		else if (ac <= 5)
			sort_small_4_5(a, ac);
		else
		{
			a->stack = (int *)malloc (sizeof(int) * ac);
			a->min = (int *)malloc (sizeof(int) * ac);
			fill_0(a->stack, ac);
			fill_0(a->min, ac);
			index_gen(a, ac);
			a->big = bigy(a, a->stack, ac);
			sort_big(a, ac);
			free(a->min);
			free(a->stack);
		}
	}
}
