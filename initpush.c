/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initpush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:11:11 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/08/12 16:23:46 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_isinlist(t_list *lst, int i)
{
	while (lst)
	{
		if (*((int *)lst->content) == i)
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	ft_initpush(t_data *ps)
{
	int		size;
	t_stack	**src;
	t_stack	**des;

	src = &(ps->ha);
	des = &(ps->hb);
	if (*src == NULL)
		return ;
	size = ft_stacksize(*src);
	while (size > 0)
	{
		if (!ft_isinlist(ps->lis, (*src)->order))
		{
			ft_push(src, des);
			ft_lstadd_back(&(ps->sol), ft_lstnew("pb"));
		}
		else if (size > 1)
		{
			ft_rot(src);
			ft_lstadd_back(&(ps->sol), ft_lstnew("ra"));
		}
		size--;
	}
	ft_lstclear(&(ps->lis), free);
}
