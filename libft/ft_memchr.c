/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:48:59 by anlima            #+#    #+#             */
/*   Updated: 2023/11/20 16:38:51 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	i = -1;
	str = (char *)s;
	while (++i < n)
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return (&str[i]);
	}
	return (0);
}
