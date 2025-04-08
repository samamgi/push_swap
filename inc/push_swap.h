/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:18:35 by ssadi-ou          #+#    #+#             */
/*   Updated: 2025/04/08 16:27:08 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(int content);

void				ft_lstadd_front(t_list **lst, t_list *new);

t_list				*ft_lstlast(t_list *lst);

void				ft_lstadd_back(t_list **lst, t_list *new);

int					ft_lstsize(t_list *lst);

void				printlst(t_list *lst);

void				ft_lstdelone(t_list *lst);

void				ft_lstclear(t_list **lst);

void				push(t_list **stack_to, t_list **stack_from);

void				pa(t_list **stack_a, t_list **stack_b);

void				pb(t_list **stack_a, t_list **stack_b);

void				swap(t_list **lst);

void				sa(t_list **stack_a);

void				sb(t_list **stack_b);

void				ss(t_list **stack_a, t_list **stack_b);

void				rotate(t_list **lst);

void				ra(t_list **stack_a);

void				rb(t_list **stack_b);

void				rr(t_list **stack_a, t_list **stack_b);

void				reverse_rotate(t_list **lst);

void				rra(t_list **stack_a);

void				rrb(t_list **stack_b);

void				rrr(t_list **stack_a, t_list **stack_b);

void				swap_list(t_list **a, t_list **b);

void				sort_list(t_list **lst, int size);

void				lst_set_index(t_list *lst);

bool				parsing_check(const char *str, int *result);

int					check_doublon(t_list **lst);

int					is_sorted(t_list **lst);

void				free_split(char **split);

int					get_distance(t_list **stack_a);

void				index_iter(t_list **stack_a, int n);

void				sort_3(t_list **stack_a);

void				sort_4(t_list **stack_a, t_list **stack_b);

void				sort_5(t_list **stack_a, t_list **stack_b);

void				ez_sort(t_list **stack_a, t_list **stack_b, int size);

void				radix_sort(t_list **stack_a, t_list **stack_b, int size);

int					init_stack_utils(t_list **lst, char **av, int i, int n);

int					init_stack(t_list **lst, char **av);

void				sort_all(t_list **stack_a, t_list **stack_b);

int					two_args(char **av, t_list **stack_a, t_list **stack_b);

int					init_check_error(int ac, char **av, t_list **stack_a,
						t_list **stack_b);

#endif