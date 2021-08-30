/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 17:38:19 by gsiddiqu          #+#    #+#             */
/*   Updated: 2021/08/16 14:43:05 by gsiddiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef struct s_path
{
	int	rr;
	int	ra;
	int	rb;
	int	pathlen;
}	t_path;

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
t_list	*ft_getstacklst(t_stack *st);
t_list	*ft_getstacklstord(t_stack *st);
void	ft_stackclear(t_stack **st);
t_stack	*ft_stacknew(int val, int order);
int		ft_stacksize(t_stack *st);
t_stack	*ft_copystk(t_stack *stk);
void	ft_push(t_stack **src, t_stack **des);
void	ft_rot(t_stack **stk);
void	ft_revrot(t_stack **stk);
void	ft_swap(t_stack **stk);
void	ft_applyrrs(t_data *ps, int num);
void	ft_applyras(t_data *ps, int num);
void	ft_applyrbs(t_data *ps, int num);
int		ft_checkinput(int argc, char **argv);
void	ft_initialize(t_stack **ha, int n, char **argv, int argc);
t_list	*ft_analyse(t_stack *stk);
void	ft_initpush(t_data *ps);
int		ft_getoptrotnum(t_stack *stko, int num);
t_path	ft_findoptinsert(t_data *ps);
void	ft_makeoptinsert(t_data *ps);
void	ft_rottohead(t_data *ps);
void	ft_algsmall(t_data *ps);
void	ft_printresult(t_list *lst);
void	ft_crunch(t_list **sol);
void	ft_err(void);
int		ft_mod(int num);
void	ft_freesplit(char **arr);
void	phfree(void *c);
void	ft_printlst(t_list *lst);
void	ft_printstk(t_stack *stk, char chr);
void	ft_printswapbuff(t_list *lst);
void	ft_printsol(t_list *lst);
void	ft_printlis(t_list *lst);
void	ft_print_status(t_data *ps);

#endif