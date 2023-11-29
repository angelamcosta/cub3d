/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:43:25 by anlima            #+#    #+#             */
/*   Updated: 2023/11/29 15:44:37 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	save_rgb(char **rgb, char pos);

void	save_rgb(char **rgb, char pos)
{
	int	i;

	i = -1;
	if (pos == 'C')
	{
		while (++i < 3)
			map()->ceiling[i] = ft_atoi(rgb[i]);
	}
	else
	{
		while (++i < 3)
			map()->floor[i] = ft_atoi(rgb[i]);
	}
}
