/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 20:59:41 by gohar             #+#    #+#             */
/*   Updated: 2021/08/12 16:48:36 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static t_list	*ft_getpotlst(t_list *lst)
{
	t_list	*pot_list;
	t_list	*elem1;
	t_list	*elem2;
	int		*i;

	pot_list = NULL;
	elem1 = lst;
	while (elem1)
	{
		i = malloc(sizeof(int));
		*i = 0;
		elem2 = elem1;
		while (elem2)
		{
			if (*((int *)elem2->content) > *((int *)elem1->content))
				(*i)++;
			elem2 = elem2->next;
		}
		ft_lstadd_back(&pot_list, ft_lstnew(i));
		elem1 = elem1->next;
	}
	return (pot_list);
}

static void	ft_slash(t_list **lis, t_list *elem)
{
	t_list	*buff;

	if (elem == *lis)
		ft_lstclear(lis, free);
	else
	{
		buff = *lis;
		while (buff->next != elem)
			buff = buff->next;
		ft_lstclear(&(buff->next), free);
		buff->next = NULL;
	}
}

static void	ft_addtolis(int num, int pot, t_list **lis)
{
	int	*elem;

	elem = malloc(2 * sizeof(int));
	*elem = num;
	*(elem + 1) = pot;
	ft_lstadd_back(lis, ft_lstnew(elem));
}

static void	ft_tryaddlis(int num, int pot, t_list **lis)
{
	t_list	*buff;
	int		n;
	int		p;

	n = num - 1;
	buff = *lis;
	while (buff)
	{
		n = *(int *)buff->content;
		p = *(((int *)buff->content) + 1);
		if (num < n && pot > p)
		{
			ft_slash(lis, buff);
			ft_addtolis(num, pot, lis);
			return ;
		}
		if (num < n)
			break ;
		buff = buff->next;
	}
	if (num > n)
		ft_addtolis(num, pot, lis);
}

t_list	*ft_analyse(t_stack *stk)
{
	t_list	*plst;
	t_list	*lis;
	t_list	*buff;
	t_list	*lst;
	t_list	*elem;

	lst = ft_getstacklstord(stk);
	lis = NULL;
	plst = ft_getpotlst(lst);
	buff = plst;
	elem = lst;
	while (elem)
	{
		ft_tryaddlis(*(int *)(elem->content),
			 *(int *)(buff->content), &lis);
		buff = buff->next;
		elem = elem->next;
	}
	ft_lstclear(&plst, free);
	ft_lstclear(&lst, free);
	return (lis);
}
