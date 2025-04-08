/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_reverse_rotate.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:40:22 by ssadi-ou          #+#    #+#             */
/*   Updated: 2025/04/08 16:40:36 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	reverse_rotate(t_list **lst)
{
	t_list	*tmp;
	t_list	*first;

	if ((!*lst) || (ft_lstsize(*lst) == 1))
		return ;
	if (ft_lstsize(*lst) == 2)
	{
		swap(lst);
		return ;
	}
	first = *lst;
	while ((*lst)->next != NULL)
	{
		*lst = (*lst)->next;
		if ((*lst)->next->next == NULL)
		{
			(*lst)->next->next = first;
			tmp = (*lst)->next;
			first = tmp;
			(*lst)->next = NULL;
		}
	}
	*lst = first;
}

void	rra(t_list **stack_a)
{
	reverse_rotate(stack_a);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_list **stack_b)
{
	reverse_rotate(stack_b);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	ft_putendl_fd("rrr", 1);
}
