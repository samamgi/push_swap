/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:10:37 by ssadi-ou          #+#    #+#             */
/*   Updated: 2025/04/08 16:14:30 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_all(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size <= 5)
		ez_sort(stack_a, stack_b, size);
	if (size > 5)
		radix_sort(stack_a, stack_b, size);
}

int	two_args(char **av, t_list **stack_a, t_list **stack_b)
{
	av = ft_split(av[1], ' ');
	av--;
	if (init_stack(stack_a, av) == -1)
	{
		av++;
		free_split(av);
		ft_lstclear(stack_b);
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	av++;
	free_split(av);
	return (1);
}

int	init_check_error(int ac, char **av, t_list **stack_a, t_list **stack_b)
{
	if (ac == 2)
	{
		if (two_args(av, stack_a, stack_b) == -1)
			return (-1);
	}
	else if (init_stack(stack_a, av) == -1)
	{
		ft_lstclear(stack_b);
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	if (is_sorted(stack_a) == 1)
	{
		ft_lstclear(stack_b);
		ft_lstclear(stack_a);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_list	**stack_a;
	t_list	**stack_b;
	int		check;

	if (ac >= 2)
	{
		stack_a = (t_list **)malloc(sizeof(t_list *));
		stack_b = (t_list **)malloc(sizeof(t_list *));
		*stack_a = NULL;
		*stack_b = NULL;
		check = init_check_error(ac, av, stack_a, stack_b);
		if (check != 1)
			return (check);
		sort_all(stack_a, stack_b);
		ft_lstclear(stack_a);
		ft_lstclear(stack_b);
	}
	return (0);
}
