/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delim_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramory-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 19:35:11 by ramory-l          #+#    #+#             */
/*   Updated: 2018/12/11 19:41:19 by ramory-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_delim_str(const char *s, size_t delim, char *c)
{
	char *dst;
	char *temp;

	temp = ft_strsub(s, (unsigned int)delim, ft_strlen(s));
	dst = ft_strsub(s, 0, delim);
	dst = ft_strjoin(dst, c);
	dst = ft_strjoin(dst, temp);
	return (dst);
}
