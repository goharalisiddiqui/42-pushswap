/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stkfuncs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 22:45:13 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/08/12 17:03:01 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*ft_copystk(t_stack *stk)
{
	int		size;
	t_stack	*newstk;

	size = ft_stacksize(stk);
	newstk = NULL;
	while (size)
	{
		ft_addtostack(&newstk, ft_stacknew(stk->val, stk->order));
		stk = stk->next;
		size--;
	}
	return (newstk);
}

void	ft_addtostack(t_stack **st, t_stack *new)
{
	t_stack	*buff;
	int		flag;

	if (*st == NULL)
	{
		*st = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	flag = (*st)->prev->val;
	buff = *st;
	while (1)
	{
		buff = buff->next;
		if (buff->val == flag)
			break ;
	}
	new->prev = buff;
	new->next = *st;
	(*st)->prev = new;
	buff->next = new;
}

t_list	*ft_getstacklst(t_stack *st)
{
	t_list	*lst;
	int		flagval;
	int		*i;

	if (st == NULL)
		return (NULL);
	lst = NULL;
	flagval = st->prev->order;
	while (1)
	{
		i = malloc(sizeof(int));
		*i = st->val;
		ft_lstadd_back(&lst, ft_lstnew(i));
		if (st->order == flagval)
			break ;
		st = st->next;
	}
	return (lst);
}

t_list	*ft_getstacklstord(t_stack *st)
{
	t_list	*lst;
	int		flagval;
	int		*i;

	if (st == NULL)
		return (NULL);
	lst = NULL;
	flagval = st->prev->order;
	while (1)
	{
		i = malloc(sizeof(int));
		*i = st->order;
		ft_lstadd_back(&lst, ft_lstnew(i));
		if (st->order == flagval)
			break ;
		st = st->next;
	}
	return (lst);
}

void	ft_stackclear(t_stack **st)
{
	t_stack	*buff;
	int		headval;

	if (*st == NULL)
		return ;
	headval = (*st)->prev->order;
	buff = *st;
	while (1)
	{
		free(buff);
		buff = buff->next;
		if (buff->order == headval)
			break ;
	}
	free(buff);
	*st = NULL;
}
