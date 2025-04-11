/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ez_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:12:08 by ssadi-ou          #+#    #+#             */
/*   Updated: 2025/04/08 16:12:57 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_3(t_list **stack_a)
{
	t_list	*current;

	current = *stack_a;
	if ((current->index == 0) && ((current->next->index) != 1))
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (current->index == 1)
	{
		if (current->next->index == 2)
			rra(stack_a);
		else
			sa(stack_a);
	}
	else if (current->index == 2)
	{
		if (current->next->index == 1)
		{
			ra(stack_a);
			sa(stack_a);
		}
		else
			ra(stack_a);
	}
}

void	sort_4(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	distance = get_distance(stack_a);
	if (distance == 1)
		sa(stack_a);
	if (distance == 2)
	{
		ra(stack_a);
		sa(stack_a);
	}
	if (distance == 3)
		rra(stack_a);
	if (is_sorted(stack_a) == 1)
		return ;
	pb(stack_a, stack_b);
	index_iter(stack_a, -1);
	sort_3(stack_a);
	index_iter(stack_a, 1);
	pa(stack_a, stack_b);
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	distance = get_distance(stack_a);
	if (distance == 1)
		sa(stack_a);
	if (distance == 2)
	{
		ra(stack_a);
		sa(stack_a);
	}
	if (distance == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	if (distance == 4)
		rra(stack_a);
	if (is_sorted(stack_a) == 1)
		return ;
	pb(stack_a, stack_b);
	index_iter(stack_a, -1);
	sort_4(stack_a, stack_b);
	index_iter(stack_a, 1);
	pa(stack_a, stack_b);
}

void	ez_sort(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 2)
		sa(stack_a);
	if (size == 3)
		sort_3(stack_a);
	if (size == 4)
		sort_4(stack_a, stack_b);
	if (size == 5)
		sort_5(stack_a, stack_b);
}

void	radix_sort(t_list **stack_a, t_list **stack_b, int size)
{
	t_list	*current;
	int		j;
	int		i;

	i = 0;
	current = *stack_a;
	while (is_sorted(stack_a) == 0)
	{
		j = 0;
		while (j < size)
		{
			current = *stack_a;
			if (((current->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (ft_lstsize(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}
