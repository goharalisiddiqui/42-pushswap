/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movefuncs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 00:29:40 by gohar             #+#    #+#             */
/*   Updated: 2021/08/12 16:18:38 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_push(t_stack **src, t_stack **des)
{
	t_stack	*buff;

	if (*src == NULL)
		return ;
	buff = *src;
	if (ft_stacksize(buff) == 1)
		*src = NULL;
	else
	{
		(*src)->prev->next = (*src)->next;
		(*src)->next->prev = (*src)->prev;
		*src = (*src)->next;
	}
	ft_addtostack(des, buff);
	ft_revrot(des);
}

void	ft_rot(t_stack **stk)
{
	if (*stk != NULL)
		*stk = (*stk)->next;
}

void	ft_revrot(t_stack **stk)
{
	if (*stk != NULL)
		*stk = (*stk)->prev;
}

void	ft_swap(t_stack **stk)
{
	t_stack	*buff1;
	t_stack	*buff2;

	if (*stk == NULL || ft_stacksize(*stk) == 1)
		return ;
	buff1 = ft_stacknew((*stk)->next->val, (*stk)->next->order);
	buff2 = ft_stacknew((*stk)->val, (*stk)->order);
	buff1->next = buff2;
	buff2->prev = buff1;
	if (ft_stacksize(*stk) == 2)
	{
		buff1->prev = buff2;
		buff2->next = buff1;
	}
	else
	{
		buff1->prev = (*stk)->prev;
		buff2->next = (*stk)->next->next;
		(*stk)->prev->next = buff1;
		(*stk)->next->next->prev = buff2;
	}
	free((*stk)->next);
	free(*stk);
	*stk = buff1;
}
