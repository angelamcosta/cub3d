/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:19:29 by anlima            #+#    #+#             */
/*   Updated: 2023/12/01 16:46:02 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	set_row_col(void);
int		is_valid_char(char c);
void	handle_spaces(char **map, int rows, int cols);

void	set_row_col(void)
{
	int		i;
	size_t	len;
	size_t	max_len;
	char	*new_row;

	i = -1;
	max_len = 0;
	while (map()->map[++i])
	{
		len = ft_strlen(map()->map[i]);
		if (len > max_len)
			max_len = len;
	}
	map()->cols = max_len;
	i = -1;
	while (map()->map[++i])
	{
		len = ft_strlen(map()->map[i]);
		if (len < max_len)
		{
			while (len++ < max_len)
			{
				new_row = ft_strjoin_char(map()->map[i], '0');
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

void	handle_spaces(char **map, int rows, int cols)
{
	int	i;
	int	j;

	i = -1;
	while (++i < rows && map[i])
	{
		if (map[i][0] == ' ')
			map[i][0] = '0';
		if (map[i][cols - 1] == ' ')
			map[i][cols - 1] = '0';
	}
	j = -1;
	while (++j < cols)
	{
		if (map[0][j] == ' ')
			map[0][j] = '0';
		if (map[rows - 1][j] == ' ')
			map[rows - 1][j] = '0';
	}
}
