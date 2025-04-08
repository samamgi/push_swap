/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:15:23 by ssadi-ou          #+#    #+#             */
/*   Updated: 2025/04/08 16:15:26 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	init_stack_utils(t_list **lst, char **av, int i, int n)
{
	*lst = ft_lstnew(n);
	while (av[++i])
	{
		n = 0;
		if ((parsing_check(av[i], &n) == false) || (ft_strlen(av[i]) == 0))
		{
			ft_lstclear(lst);
			return (-1);
		}
		ft_lstadd_back(lst, ft_lstnew(n));
	}
	if (check_doublon(lst) == 1)
	{
		ft_lstclear(lst);
		return (-1);
	}
	lst_set_index(*lst);
	return (1);
}

int	init_stack(t_list **lst, char **av)
{
	int	i;
	int	n;

	i = 1;
	n = 0;
	if ((parsing_check(av[1], &n) == false) || (ft_strlen(av[1]) == 0))
	{
		ft_lstclear(lst);
		return (-1);
	}
	return (init_stack_utils(lst, av, i, n));
}
