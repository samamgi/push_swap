/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:39:31 by ssadi-ou          #+#    #+#             */
/*   Updated: 2025/04/08 16:39:38 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(t_list **lst)
{
	int	tmp_cont;
	int	tmp_index;

	if ((ft_lstsize(*lst) == 0) || ((*lst)->next == NULL))
		return ;
	tmp_cont = (*lst)->content;
	tmp_index = (*lst)->index;
	(*lst)->content = (*lst)->next->content;
	(*lst)->index = (*lst)->next->index;
	(*lst)->next->content = tmp_cont;
	(*lst)->next->index = tmp_index;
}

void	sa(t_list **stack_a)
{
	swap(stack_a);
	ft_putendl_fd("sa", 1);
}

void	sb(t_list **stack_b)
{
	swap(stack_b);
	ft_putendl_fd("sb", 1);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_putendl_fd("ss", 1);
}
