/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramory-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:25:43 by ramory-l          #+#    #+#             */
/*   Updated: 2018/11/28 19:36:49 by ramory-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(long int n, int sign)
{
	if (n * sign > 0 && sign < 0)
		return (0);
	if (n * sign < 0 && sign > 0)
		return (-1);
	return (n * sign);
}

int			ft_atoi(const char *str)
{
	long int		n;
	int				neg;

	n = 0;
	neg = 1;
	while (*str == ' ' || *str == '\f' ||
			*str == '\n' || *str == '\t' ||
			*str == '\r' || *str == '\v')
		str++;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + *str - '0';
		str++;
	}
	return (ft_check(n, neg));
}
