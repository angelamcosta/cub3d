/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:25:03 by anlima            #+#    #+#             */
/*   Updated: 2024/01/18 18:06:26 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int		get_max_len(void);
void	set_player(int row, int col, char mark);

void	set_player(int row, int col, char mark)
{
	map()->player = map()->map[row][col];
	map()->pos.x = (double)col + 0.5;
	map()->pos.y = (double)row + 0.5;
	map()->map[row][col] = mark;
}

int	get_max_len(void)
{
	int	i;
	int	len;
	int	max_len;

	i = -1;
	max_len = 0;
	while (map()->map && map()->map[++i])
	{
		len = ft_strlen(map()->map[i]);
		if (len > max_len)
			max_len = len;
	}
	return (max_len);
}
