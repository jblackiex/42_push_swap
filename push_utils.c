/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbordoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:46:54 by nbordoni          #+#    #+#             */
/*   Updated: 2023/03/18 11:47:03 by nbordoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

long int	ft_atol(const char *str)
{
	long	i;
	long	nbr;
	int		isneg;

	i = 0;
	nbr = 0;
	isneg = 0;
	while (str[i] != '\0' && (str[i] == 32 || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] != '\0' && str[i] == '-')
	{
		isneg = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
		nbr = (nbr * 10) + (str[i++] - '0');
	if (isneg == 1)
		return (-nbr);
	return (nbr);
}

int	sort_checking(int *a, int size, t_push *big)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (big->x2)
	{
		if (a[0] < a[1] && a[1] < a[2])
			return (0);
	}
	else if (big->dimy != size)
		return (1);
	while (i < (size - 1))
	{
		if (a[i] > a[i + 1])
			count = 1;
		i++;
	}
	return (count);
}

void	bigy5(t_push *ar, int *a, int ac)
{
	int			i;
	int			big;
	static int	k;

	i = 0;
	while (a[i] == ar->big || a[i] == ar->big2)
		i++;
	big = a[i];
	i = 0;
	while (i < ac)
	{
		if (k && a[i] >= big && a[i] != ar->big && a[i] != ar->big2)
			big = a[i];
		else if (!k && a[i] >= big && a[i] != ar->big)
			big = a[i];
		i++;
	}
	if (!k)
		ar->big2 = big;
	else
		ar->big3 = big;
	k++;
}

void	init_elem(t_push *a)
{
	a->stacka = 0;
	a->flag = 0;
	a->big = 0;
	a->sizeb = 0;
	a->pos = 0;
	a->dimy = 0;
	a->x = 0;
	a->x2 = 0;
	a->big2 = 0;
	a->big = 0;
	a->big3 = 0;
}
