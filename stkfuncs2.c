/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stkfuncs2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 22:45:13 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/08/12 16:17:46 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*ft_stacknew(int val, int order)
{
	t_stack	*elem;

	elem = malloc(sizeof(t_stack));
	if (elem == NULL)
		return (NULL);
	elem->val = val;
	elem->order = order;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

int	ft_stacksize(t_stack *st)
{
	int	i;
	int	flag;

	if (st == NULL)
		return (0);
	flag = st->prev->order;
	i = 0;
	while (1)
	{
		i++;
		if (st->order == flag)
			break ;
		st = st->next;
	}
	return (i);
}
