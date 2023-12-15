/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:19:29 by anlima            #+#    #+#             */
/*   Updated: 2023/12/14 14:51:39 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	set_row_col(void);
int		mark_regions(void);
int		is_map_closed(void);
int		is_valid_char(char c);
void	dfs(int row, int col, char mark);

void	set_row_col(void)
{
	int		i;
	size_t	len;
	size_t	max_len;
	char	*new_row;

	i = -1;
	max_len = 0;
	while (map()->map && map()->map[++i])
	{
		len = ft_strlen(map()->map[i]);
		if (len > max_len)
			max_len = len;
	}
	map()->cols = max_len;
	i = -1;
	while (map()->map && map()->map[++i])
	{
		len = ft_strlen(map()->map[i]);
		if (len < max_len)
		{
			while (len++ < max_len)
			{
				new_row = ft_strjoin_char(map()->map[i], ' ');
				free(map()->map[i]);
				map()->map[i] = new_row;
			}
		}
	}
}

int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ');
}

void	dfs(int row, int col, char mark)
{
	if (row < 0 || row >= map()->rows || col < 0 || col >= map()->cols)
		return ;
	if (map()->map[row][col] == 'S' || map()->map[row][col] == 'N'
		|| map()->map[row][col] == 'E' || map()->map[row][col] == 'W')
	{
		if (map()->pos[0] != '-')
			return ;
		if (row == 0 || row == map()->rows - 1 || col == 0 || col == map()->cols - 1)
			return ;
		map()->pos[0] = map()->map[row][col];
		map()->pos[1] = row;
		map()->pos[2] = col;
		map()->map[row][col] = mark;
		return ;
	}
	if (map()->map[row][col] != '0')
		return ;
	map()->map[row][col] = mark;
	dfs(row + 1, col, mark);
	dfs(row - 1, col, mark);
	dfs(row, col + 1, mark);
	dfs(row, col - 1, mark);
}

int	mark_regions(void)
{
	int		flag;
	char	mark;

	flag = 0;
	mark = '.';
	for (int i = 0; i < map()->rows; ++i)
	{
		for (int j = 0; j < map()->cols; ++j)
		{
			if (map()->map[i][j] == '0')
			{
				dfs(i, j, mark);
				flag = 1;
			}
		}
	}
	return (flag);
}

int	is_map_closed(void)
{
	if (!mark_regions())
		return (0);
	for (int i = 0; i < map()->rows; ++i)
	{
		for (int j = 0; j < map()->cols; ++j)
		{
			if (map()->map[i][j] == '.')
			{
				if (!check_char(i, j))
					return (0);
			}
		}
	}
	return (1);
}
