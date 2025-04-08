/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_funcs_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:41:04 by ssadi-ou          #+#    #+#             */
/*   Updated: 2025/04/08 16:41:55 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_lstdelone(t_list *lst)
{
	if (!lst)
		return ;
	free(lst);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = temp;
	}
	free(lst);
}

void	printlst(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
	{
		ft_printf("liste NULLE\n\n");
		return ;
	}
	tmp = lst;
	while (tmp != NULL)
	{
		ft_printf("content: %i ", tmp->content);
		ft_printf("index: %i\n", tmp->index);
		if (tmp->next == NULL)
			ft_printf("next: NULL\n");
		tmp = tmp->next;
	}
	ft_putchar_fd('\n', 1);
}
