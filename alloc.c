/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbordoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:47:43 by nbordoni          #+#    #+#             */
/*   Updated: 2023/03/18 11:47:50 by nbordoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	fill_0(int *a, int ac)
{
	int	i;

	i = 0;
	while (i < ac)
		a[i++] = 0;
}

// per rra //
void	ft_memcpy3(int *src, int size)
{
	int	i;
	int	j;
	int	*d;

	i = 0;
	j = 0;
	d = (int *)malloc (sizeof(int) * size);
	while (i++ < size)
		d[i] = src[i];
	i = 1;
	while (j < size - 1)
		src[i++] = d[j++];
	free(d);
}

// pa, e pb //
int	*ft_memcpy2(int *src, int size, int num)
{
	int	*d;
	int	i;
	int	j;

	d = NULL;
	if (num == 0)
	{
		i = 0;
		j = 1;
		d = (int *)malloc (sizeof(int) * size);
		while (i < size)
			d[i++] = src[j++];
		free (src);
	}
	else if (num == 1)
	{
		i = 1;
		j = 0;
		d = (int *)malloc (sizeof(int) * size);
		while (i < size && size != 1)
			d[i++] = src[j++];
		free (src);
	}
	return (d);
}

int	not_found(int value, t_push *a, int dim)
{
	int	i;

	i = 0;
	if (!dim)
		return (1);
	while (i < dim)
	{
		if (a->min[i] == value)
			return (0);
		i++;
	}
	return (1);
}

void	index_gen(t_push *a, int ac)
{
	int				i;
	static int		j;

	if (j == ac)
		return ;
	i = 0;
	a->temp = a->big;
	a->x = i;
	if (j == ac - 1)
		a->x = a->pos;
	while (i < ac && (j != ac - 1))
	{
		if (a->temp > a->stacka[i] && not_found(a->stacka[i], a, j))
		{
			a->temp = a->stacka[i];
			a->x = i;
		}
		i++;
	}
	a->stack[a->x] = j;
	a->min[j++] = a->temp;
	index_gen(a, ac);
}
