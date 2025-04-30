/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:07:13 by ssadi-ou          #+#    #+#             */
/*   Updated: 2025/04/08 16:07:17 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap_list(t_list **a, t_list **b)
{
	t_list	*swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

void	sort_list(t_list **lst, int size)
{
	int	swapped;
	int	i;

	i = 0;
	swapped = 1;
	while (1)
	{
		swapped = 0;
		i = 0;
		while (i < size - 1)
		{
			if (lst[i]->content > lst[i + 1]->content)
			{
				swap_list(&lst[i], &lst[i + 1]);
				swapped = 1;
			}
			i++;
		}
		if (!swapped)
			break ;
	}
}

void	lst_set_index(t_list *lst)
{
	int		i;
	int		size;
	t_list	*current;
	t_list	**tab;

	i = 0;
	size = ft_lstsize(lst);
	current = lst;
	tab = (t_list **)malloc(sizeof(t_list *) * size);
	if (!tab)
		return ;
	while (i < size)
	{
		tab[i] = current;
		current = current->next;
		i++;
	}
	sort_list(tab, size);
	i = 0;
	while (i < size)
	{
		tab[i]->index = i;
		i++;
	}
	free(tab);
}

bool	parsing_check(const char *str, int *result)
{
	int	i;

	i = 0;
	if (!str)
		return (false);
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (!(ft_strncmp(&str[i], "-2147483648", (ft_strlen("-2147483648") + 1))))
	{
		*result = -2147483648;
		return (true);
	}
	if (str[i] && (str[i] == '+' || str[i] == '-'))
		i++;
	if (!str[i])
		return (false);
	if (str[i] && (str[i] == '+' || str[i] == '-'))
		return (false);
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
		i++;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i])
		return (false);
	return (ft_atoi(str, result));
}

int	check_doublon(t_list **lst)
{
	t_list	*current;
	t_list	*cmp;

	current = *lst;
	while (current->next != NULL)
	{
		cmp = current->next;
		while (cmp != NULL)
		{
			if (current->content == cmp->content)
				return (1);
			cmp = cmp->next;
		}
		current = current->next;
	}
	return (0);
}
