/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 20:10:04 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/08/12 20:10:42 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				val;
	int				order;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_data
{
	int		n;
	t_stack	*ha;
	t_stack	*hb;
	t_list	*lis;
	t_list	*sol;
}	t_data;

void	ft_addtostack(t_stack **st, t_stack *new);
void	ft_stackclear(t_stack **st);
t_stack	*ft_stacknew(int val, int order);
int		ft_stacksize(t_stack *st);
t_stack	*ft_copystk(t_stack *stk);
void	ft_push(t_stack **src, t_stack **des);
void	ft_rot(t_stack **stk);
void	ft_revrot(t_stack **stk);
void	ft_swap(t_stack **stk);
int		ft_checkinput(int argc, char **argv);
void	ft_initialize(t_stack **ha, int n, char **argv, int argc);
void	ft_err(void);
int		ft_mod(int num);
void	ft_freesplit(char **arr);
void	phfree(void *c);
int		ft_applyrots(t_data *ps, char *move);
int		ft_applydual(t_data *ps, char *move);
int		ft_applyrest(t_data *ps, char *move);
void	ft_readsol(t_data *ps);
int		ft_applysol(t_data *ps);

#endif