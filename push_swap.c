/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbordoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:32:00 by nbordoni          #+#    #+#             */
/*   Updated: 2023/02/27 11:32:03 by nbordoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	check_doubles(t_push *a, int ac)
{
	int	i;
	int	j;
	int	cont;

	i = 0;
	a->flag = 0;
	while ((i < ac - 1) && a->flag == 0)
	{
		j = 0;
		cont = a->stacka[i];
		while ((j < ac - 1) && a->flag == 0)
		{
			if (a->stacka[j] == cont && i != j)
			{
				a->flag = 1;
				return (a->flag);
			}
			j++;
		}
		i++;
	}
	return (a->flag);
}

int	lett_go(char *av)
{
	int	i;

	i = 0;
	if (av[0] == '-' && av[1] == 48)
		return (1);
	if (!av[i] || (av[0] == 48 && (av[1] >= 48 && av[1] <= 57))
		|| (av[0] == '-' && (av[1] == 48 && av[2])))
		return (1);
	else if (av[i] == '-')
		i++;
	if (i && !av[i])
		return (1);
	while (av[i])
	{
		if (!(av[i] >= 48 && av[i] <= 57))
			return (1);
		i++;
	}
	return (0);
}

int	check_av_save(char **av, int ac, t_push	*a)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac && a->flag == 0)
	{
		j = 0;
		while (a->flag == 0)
		{
			if (ft_atol(av[i]) < -2147483648 || ft_atol(av[i]) > 2147483647)
				a->flag = 1;
			if (lett_go(av[i]) && !a->flag)
				a->flag = 1;
			if (j == 0 && !a->flag)
			{
				if (i == 1)
					a->stacka = malloc(sizeof(int) * (ac - 1));
				a->stacka[i - 1] = ft_atoi(av[i]);
				break ;
			}
			j++;
		}
		i++;
	}
	return (a->flag);
}

int	main(int ac, char **av)
{
	t_push	arr;

	init_elem(&arr);
	if (ac <= 1)
		return (1);
	else if (check_av_save(av, ac, &arr) || check_doubles(&arr, ac))
	{
		if (arr.stacka)
			free(arr.stacka);
		ft_printf("Error\n");
		return (1);
	}
	else
	{
		arr.stackb = malloc(sizeof(int) * (ac - 1));
		push_core(&arr, ac - 1);
		free (arr.stacka);
		free(arr.stackb);
	}
	return (0);
}
