/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:19:53 by anlima            #+#    #+#             */
/*   Updated: 2023/12/04 21:07:14 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	is_valid_path(void);
int	is_valid_str(char *str);
int	check_char(int i, int j);

int	check_char(int i, int j)
{
	if (((i - 1 > 0 && i < map()->rows && (map()->map[i - 1][j] != '1' && map()->map[i - 1][j] != '.')) ||
		(i >= 0 && i + 1 < map()->rows && (map()->map[i + 1][j] != '1' && map()->map[i + 1][j] != '.')) ||
		(j - 1 > 0 && j < map()->cols && (map()->map[i][j - 1] != '1' && map()->map[i][j - 1] != '.')) ||
		(j >= 0 && j + 1 < map()->cols && (map()->map[i][j + 1] != '1' && map()->map[i][j + 1] != '.'))))
			return (0);
	return (1);
}

int	is_valid_str(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!is_valid_char(str[i]))
			return (0);
	}
	return (1);
}

int	is_valid_path(void)
{
	int	row;
	int	col;

	row = map()->pos[1];
	col = map()->pos[2];
	if (!row && !col)
		return (0);
	if (map()->map[row + 1][col] == '1' &&
		map()->map[row - 1][col] == '1' &&
		map()->map[row][col + 1]  == '1' &&
		map()->map[row][col - 1] == '1')
		return (0);
	return (1);
}
