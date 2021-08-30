/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 20:09:23 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/08/30 12:18:07 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_applyrest(t_data *ps, char *move)
{
	if (!ft_strncmp(move, "pa", 3))
	{
		ft_push(&(ps->hb), &(ps->ha));
		return (1);
	}
	else if (!ft_strncmp(move, "pb", 3))
	{
		ft_push(&(ps->ha), &(ps->hb));
		return (1);
	}
	else if (!ft_strncmp(move, "sa", 3))
	{
		ft_swap(&(ps->ha));
		return (1);
	}
	else if (!ft_strncmp(move, "sb", 3))
	{
		ft_swap(&(ps->hb));
		return (1);
	}
	return (0);
}

int	ft_applyrots(t_data *ps, char *move)
{
	if (!ft_strncmp(move, "ra", 4))
	{
		ft_rot(&(ps->ha));
		return (1);
	}
	else if (!ft_strncmp(move, "rb", 3))
	{
		ft_rot(&(ps->hb));
		return (1);
	}
	else if (!ft_strncmp(move, "rra", 4))
	{
		ft_revrot(&(ps->ha));
		return (1);
	}
	else if (!ft_strncmp(move, "rrb", 4))
	{
		ft_revrot(&(ps->hb));
		return (1);
	}
	return (0);
}

int	ft_applydual(t_data *ps, char *move)
{
	if (!ft_strncmp(move, "rrr", 4))
	{
		ft_revrot(&(ps->ha));
		ft_revrot(&(ps->hb));
		return (1);
	}
	else if (!ft_strncmp(move, "rr", 3))
	{	
		ft_rot(&(ps->ha));
		ft_rot(&(ps->hb));
		return (1);
	}
	else if (!ft_strncmp(move, "ss", 3))
	{
		ft_swap(&(ps->ha));
		ft_swap(&(ps->hb));
		return (1);
	}
	return (0);
}

int	ft_applysol(t_data *ps)
{
	t_list	*elem;
	char	*move;
	int		flag;

	elem = ps->sol;
	while (elem)
	{
		flag = 0;
		move = (char *)elem->content;
		flag += ft_applyrots(ps, move);
		flag += ft_applydual(ps, move);
		flag += ft_applyrest(ps, move);
		if (flag != 1)
			return (0);
		elem = elem->next;
	}
	return (1);
}

void	ft_readsol(t_data *ps)
{
	int		flag;
	t_list	*lst;
	char	*str;

	flag = 1;
	lst = NULL;
	str = "placeholder";
	while (flag == 1 && *str != '\0')
	{
		flag = get_next_line(STDIN_FILENO, &str);
		if (*str != '\0')
			ft_lstadd_back(&lst, ft_lstnew(str));
		else
			free(str);
	}
	ps->sol = lst;
}
