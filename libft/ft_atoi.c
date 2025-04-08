/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <ssadi-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 01:19:39 by ssadi-ou          #+#    #+#             */
/*   Updated: 2025/04/02 01:03:06 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

// int	ft_atoi(const char *nptr)
// {
// 	int	i;
// 	int	n;
// 	int	result;

// 	i = 0;
// 	n = 1;
// 	result = 0;
// 	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
// 	{
// 		i++;
// 	}
// 	if (nptr[i] == '+' || nptr[i] == '-')
// 	{
// 		if (nptr[i] == '-')
// 			n *= -1;
// 		i++;
// 	}
// 	while (nptr[i] >= 48 && nptr[i] <= 57)
// 	{
// 		result = result * 10 + (nptr[i] - 48);
// 		i++;
// 	}
// 	return (result * n);
// }
bool	ft_atoi(const char *str, int *result)
{
	int	i;
	int	n;

	i = 0;
	n = 1;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			n = -n;
		i++;
	}
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
	{
		if (*result > INT_MAX / 10 || (*result == INT_MAX / 10 && (str[i]
					- 48) > INT_MAX % 10) || *result < INT_MIN / 10
			|| (*result == INT_MIN / 10 && (str[i] - 48) > INT_MIN % 10))
			return (false);
		*result = *result * 10 + (str[i] - 48);
		i++;
	}
	*result *= n;
	return (true);
}
