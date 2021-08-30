/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpfuncs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 16:21:48 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/08/16 12:36:31 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_printresult(t_list *lst)
{
	while (lst != NULL)
	{
		ft_printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
}

void	ft_makeoptinsert(t_data *ps)
{
	t_path	optpath;

	optpath = ft_findoptinsert(ps);
	ft_applyrrs(ps, optpath.rr);
	ft_applyras(ps, optpath.ra);
	ft_applyrbs(ps, optpath.rb);
	ft_push(&(ps->hb), &(ps->ha));
	ft_lstadd_back(&(ps->sol), ft_lstnew("pa"));
}

void	ft_rottohead(t_data *ps)
{
	int	num;

	num = ft_getoptrotnum(ps->ha, 1);
	while (num != 0)
	{
		if (num > 0)
		{
			ft_rot(&(ps->ha));
			ft_lstadd_back(&(ps->sol), ft_lstnew("ra"));
			num--;
		}
		else
		{
			ft_revrot(&(ps->ha));
			ft_lstadd_back(&(ps->sol), ft_lstnew("rra"));
			num++;
		}
	}
}

static int	ft_ispseudosorted(t_stack *stk)
{
	int	size;
	int	flag;

	flag = 0;
	size = ft_stacksize(stk);
	while (size)
	{
		if (stk->order > stk->next->order)
			flag++;
		stk = stk->next;
		size--;
	}
	if (flag == 1)
		return (1);
	return (0);
}

void	ft_algsmall(t_data *ps)
{
	while (ft_stacksize(ps->ha) > 3)
	{
		ft_push(&(ps->ha), &(ps->hb));
		ft_lstadd_back(&(ps->sol), ft_lstnew("pb"));
	}
	if (!ft_ispseudosorted(ps->ha))
	{
		ft_swap(&(ps->ha));
		ft_lstadd_back(&(ps->sol), ft_lstnew("sa"));
	}
}
