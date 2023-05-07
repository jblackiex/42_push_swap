/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbordoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:32:06 by nbordoni          #+#    #+#             */
/*   Updated: 2023/02/27 11:32:09 by nbordoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdint.h> 
# include <math.h>
# include "libft/libft.h"

//STRUCT//

typedef struct s_push
{
	int	flag;
	int	*stacka;
	int	*stack;
	int	*min;
	int	*stackb;
	int	sizeb;
	int	x2;
	int	x;
	int	temp;
	int	dimy;
	int	pos;
	int	big;
	int	big2;
	int	big3;
}	t_push;

//FUNCTION//

long int	ft_atol(const char *str);
void		push_core(t_push *a, int ac);
int			sort_checking(int *a, int size, t_push *big);
void		sa_sort(t_push *a);
void		ra_sort(t_push *a, int ac);
void		ra_sortb(t_push *a, int ac);
int			*ft_memcpy2(int *src, int size, int num);
void		index_gen(t_push *a, int ac);
void		bigy5(t_push *ar, int *a, int ac);
void		sort_big(t_push *a, int ac);
void		init_elem(t_push *a);
void		rra_sort(t_push *a, int ac);
void		ft_memcpy3(int *src, int size);
void		rra2_sort(t_push *a);
void		fill_0(int *a, int ac);
void		pb_sort(t_push *a, int ac);
void		pa_sort(t_push *a, int ac);
void		pb_sortb(t_push *a, int ac);
void		pa_sortb(t_push *a, int ac);
void		sb_sort(t_push *a);

//void    printy(t_push *a, int ac); ///// per debugging, non serve /////
/*
void    printy(t_push *a, int ac)
{
    int i;

    i = 0;
    ft_printf("\n");
    while (i < ac)
        ft_printf("%d, ", a->stacka[i++]);
    i = 0;
    ft_printf("\t\t");
    while (i < a->sizeb && a->sizeb > 0)
        ft_printf("%d, ", a->stackb[i++]);
}
*/
#endif
