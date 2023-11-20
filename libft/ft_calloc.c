/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:33:27 by anlima            #+#    #+#             */
/*   Updated: 2023/11/20 16:38:51 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*arr;

	arr = (void *)malloc(num * size);
	if (!arr)
		return (NULL);
	ft_memset(arr, 0, num * size);
	return (arr);
}
