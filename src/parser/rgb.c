/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:43:25 by anlima            #+#    #+#             */
/*   Updated: 2023/11/29 16:58:21 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int		check_rgb(char **args);
void	save_rgb(char **rgb, char pos);

int	check_rgb(char **args)
{
	int		flag;
	char	**rgb;

	flag = 0;
	rgb = ft_split(args[1], ',');
	flag = check_params(rgb);
	if (flag)
		save_rgb(rgb, *args[0]);
	free_dptr(rgb);
	return (flag);
}

void	save_rgb(char **rgb, char pos)
{
	int	i;

	i = -1;
	if (pos == 'C')
	{
		while (++i < 3)
			map()->ceiling[i] = ft_strdup(rgb[i]);
	}
	else
	{
		while (++i < 3)
			map()->floor[i] = ft_strdup(rgb[i]);
	}
}
