/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 16:21:48 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/08/30 12:04:12 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_solve(t_data *ps)
{
	ps->lis = ft_analyse(ps->ha);
	if (ft_lstsize(ps->lis) < ps->n)
	{
		if (ps->n <= 5)
			ft_algsmall(ps);
		else
			ft_initpush(ps);
	}
	if (ps->lis != NULL)
		ft_lstclear(&(ps->lis), free);
	while (ft_stacksize(ps->hb) > 0)
		ft_makeoptinsert(ps);
	ft_rottohead(ps);
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
	ft_solve(&ps);
	if (ps.ha)
		ft_stackclear(&(ps.ha));
	if (ps.hb)
		ft_stackclear(&(ps.hb));
	ft_crunch(&(ps.sol));
	ft_printresult(ps.sol);
	ft_lstclear(&(ps.sol), phfree);
	return (0);
}
