/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 01:48:50 by gohar             #+#    #+#             */
/*   Updated: 2021/08/16 14:57:16 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_freeresources(t_data *ps)
{
	if (ps->ha)
		ft_stackclear(&(ps->ha));
	if (ps->hb)
		ft_stackclear(&(ps->hb));
	ft_lstclear(&(ps->sol), free);
}

void	ft_error(t_data *ps)
{
	ft_freeresources(ps);
	ft_lstclear(&(ps->sol), free);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
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

int	main(int argc, char **argv)
{
	t_data	ps;

	if (argc == 1)
		return (0);
	ft_bzero(&ps, sizeof(t_data));
	ps.n = ft_checkinput(argc, argv);
	if (ps.n == 0)
		ft_err();
	if (ps.n == 1)
		return (0);
	ft_initialize(&(ps.ha), ps.n, argv, argc);
	ft_readsol(&ps);
	if (!ft_applysol(&ps))
		ft_error(&ps);
	if (ps.ha->order == 1 && ft_ispseudosorted(ps.ha))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_freeresources(&ps);
	return (0);
}
