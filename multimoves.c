/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multimoves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 16:03:32 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/08/12 16:19:30 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_applyrrs(t_data *ps, int num)
{
	while (num != 0)
	{
		if (num < 0)
		{
			ft_revrot(&(ps->ha));
			ft_revrot(&(ps->hb));
			ft_lstadd_back(&(ps->sol), ft_lstnew("rrr"));
			num++;
		}
		else
		{
			ft_rot(&(ps->ha));
			ft_rot(&(ps->hb));
			ft_lstadd_back(&(ps->sol), ft_lstnew("rr"));
			num--;
		}
	}
}

void	ft_applyras(t_data *ps, int num)
{
	while (num != 0)
	{
		if (num < 0)
		{
			ft_revrot(&(ps->ha));
			ft_lstadd_back(&(ps->sol), ft_lstnew("rra"));
			num++;
		}
		else
		{
			ft_rot(&(ps->ha));
			ft_lstadd_back(&(ps->sol), ft_lstnew("ra"));
			num--;
		}
	}
}

void	ft_applyrbs(t_data *ps, int num)
{
	while (num != 0)
	{
		if (num < 0)
		{
			ft_revrot(&(ps->hb));
			ft_lstadd_back(&(ps->sol), ft_lstnew("rrb"));
			num++;
		}
		else
		{
			ft_rot(&(ps->hb));
			ft_lstadd_back(&(ps->sol), ft_lstnew("rb"));
			num--;
		}
	}
}
