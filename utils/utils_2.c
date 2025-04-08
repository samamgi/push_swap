/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:07:51 by ssadi-ou          #+#    #+#             */
/*   Updated: 2025/04/08 16:10:17 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_sorted(t_list **lst)
{
	t_list	*current;

	current = *lst;
	while (current->next)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	get_distance(t_list **stack_a)
{
	t_list	*current;
	int		distance;

	current = *stack_a;
	distance = 0;
	while (current)
	{
		if (current->index == 0)
			break ;
		distance++;
		current = current->next;
	}
	return (distance);
}

void	index_iter(t_list **stack_a, int n)
{
	t_list	*first;

	first = *stack_a;
	while ((*stack_a) != NULL)
	{
		if (n == -1)
			((*stack_a)->index) -= 1;
		else if (n == 1)
			((*stack_a)->index) += 1;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = first;
}
