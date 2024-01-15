/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedroso <mpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:19:29 by anlima            #+#    #+#             */
/*   Updated: 2024/01/14 22:20:10 by mpedroso         ###   ########.fr       */
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
				map()->map[i] = ft_strdup(new_row);
				free(new_row);
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
	if ((row == 0 || row == map()->rows - 1 || col == 0 || col == map()->cols
			- 1) && map()->map[row][col] == '0')
		return ;
	if (row < 0 || row >= map()->rows || col < 0 || col >= map()->cols)
		return ;
	if (map()->map[row][col] == 'S' || map()->map[row][col] == 'N'
		|| map()->map[row][col] == 'E' || map()->map[row][col] == 'W')
	{
		if (map()->player > 0)
			return ;
		if (row == 0 || row == map()->rows - 1 || col == 0 || col == map()->cols
			- 1)
			return ;
		map()->player = map()->map[row][col];
		map()->pos.x = (double)col + 0.5;
		map()->pos.y = (double)row + 0.5;
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
	int		i;
	int		j;
	int		flag;
	char	mark;

	i = -1;
	flag = 0;
	mark = '.';
	while (++i < map()->rows)
	{
		j = -1;
		while (++j < map()->cols)
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
	int	i;
	int	j;

	i = -1;
	if (!mark_regions())
		return (0);
	while (++i < map()->rows)
	{
		j = -1;
		while (++j < map()->cols)
		{
			if (map()->map[i][j] == '0')
				return (0);
			if (map()->map[i][j] == '.')
			{
				if (!check_char(i, j))
					return (0);
			}
		}
	}
	return (1);
}
