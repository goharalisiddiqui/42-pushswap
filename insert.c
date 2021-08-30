/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:23:47 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/08/26 17:46:52 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_getoptrotnum(t_stack *stko, int num)
{
	int		count;
	int		size;
	t_list	*stklst;
	t_list	*ordlst;

	count = 0;
	stklst = ft_getstacklstord(stko);
	ordlst = stklst;
	size = ft_lstsize(stklst);
	while (stklst && *(int *)stklst->content != num)
	{
		stklst = stklst->next;
		count ++;
	}
	ft_lstclear(&ordlst, free);
	if (count > size / 2)
		return (count - size);
	else
		return (count);
}

static int	ft_getinsertlen(t_data *ps, t_stack *stk, int num)
{
	int		size;
	int		lnum;
	int		lownum;
	t_stack	*stko;

	stko = stk;
	size = ft_stacksize(stk);
	if (size == 1)
		return (0);
	lnum = ps->n + 1;
	lownum = ps->n + 1;
	while (size > 0)
	{
		if (stk->order > num && stk->order < lnum)
			lnum = stk->order;
		if (stk->order < lownum)
			lownum = stk->order;
		stk = stk->next;
		size--;
	}
	if (lnum > ps->n)
		return (ft_getoptrotnum(stko, lownum));
	return (ft_getoptrotnum(stko, lnum));
}

static int	ft_ispathflex(int path, t_stack *stk)
{
	if (path == ft_stacksize(stk) / 2)
		return (1);
	return (0);
}

static t_path	ft_getpathlen(t_data *ps, int num)
{
	int		pathB;
	int		pathA;
	t_path	path;

	pathB = ft_getoptrotnum(ps->hb, num);
	pathA = ft_getinsertlen(ps, ps->ha, num);
	if (ft_ispathflex(pathA, ps->ha) && pathB < 0 && pathA > 0)
		pathA *= -1;
	else if (ft_ispathflex(pathB, ps->ha) && pathA < 0 && pathB > 0)
		pathB *= -1;
	if (pathA * pathB < 0 || pathA == 0 || pathB == 0)
		path.rr = 0;
	else if (ft_mod(pathA) > ft_mod(pathB))
		path.rr = pathB;
	else
		path.rr = pathA;
	path.ra = pathA - path.rr;
	path.rb = pathB - path.rr;
	path.pathlen = ft_mod(path.ra) + ft_mod(path.rb) + ft_mod(path.rr);
	return (path);
}

t_path	ft_findoptinsert(t_data *ps)
{
	t_path	path;
	t_path	minpath;
	t_list	*elem;
	t_list	*ordlst;

	elem = ft_getstacklstord(ps->hb);
	ordlst = elem;
	minpath.pathlen = ps->n;
	while (elem != NULL)
	{
		path = ft_getpathlen(ps, *(int *)elem->content);
		if (path.pathlen < minpath.pathlen)
			minpath = path;
		elem = elem->next;
	}
	ft_lstclear(&ordlst, free);
	return (minpath);
}
