/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:19:29 by anlima            #+#    #+#             */
/*   Updated: 2023/11/29 15:07:09 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int		is_valid_char(char c);
int		is_closed(char **map, int rows, int cols);
int		is_valid_map(char **map, int rows, int cols);
void	handle_spaces(char **map, int rows, int cols);

int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ');
}

int	is_closed(char **map, int rows, int cols)
{
	int	i;

	i = -1;
	while (++i < rows)
	{
		if (map[i][0] != '1' || map[i][cols - 1] != '1')
			return (0);
	}
	i = -1;
	while (++i < rows)
	{
		if (map[0][i] != '1' || map[rows - 1][i] != '1')
			return (0);
	}
	return (1);
}

int	is_valid_map(char **map, int rows, int cols)
{
	int	i;
	int	j;

	i = -1;
	while (++i < rows)
	{
		j = -1;
		while (++j < cols)
		{
			if (!is_valid_char(map[i][j]))
				return (0);
		}
	}
	if (!is_closed(map, rows, cols))
	{
		handle_spaces(map, rows, cols);
		if (!is_closed(map, rows, cols))
			return (0);
	}
	return (1);
}

void	handle_spaces(char **map, int rows, int cols)
{
	int	i;
	int	j;

	i = -1;
	while (++i < rows)
	{
		if (map[i][0] == ' ')
			map[i][0] = '1';
		if (map[i][cols - 1] == ' ')
			map[i][cols - 1] = '1';
	}
	j = -1;
	while (++j < cols)
	{
		if (map[0][j] == ' ')
			map[0][j] = '1';
		if (map[rows - 1][j] == ' ')
			map[rows - 1][j] = '1';
	}
}
