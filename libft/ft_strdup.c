/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:38:37 by anlima            #+#    #+#             */
/*   Updated: 2023/11/20 16:38:51 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(char *src)
{
	char	*copy;
	int		i;

	copy = malloc(ft_strlen(src) + 1);
	if (!copy)
		return (NULL);
	i = -1;
	while (src[++i])
		copy[i] = src[i];
	copy[i] = '\0';
	return (copy);
}
