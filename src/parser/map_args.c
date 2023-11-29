/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:10:10 by anlima            #+#    #+#             */
/*   Updated: 2023/11/29 16:12:30 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	split_params(char *line);
int	read_args(char *filename);
int	check_params(char **line);

int	split_params(char *line)
{
	int		flag;
	char	**rgb;
	char	**args;

	if (*line == '\n')
		return (1);
	if (line)
		line[ft_strlen(line) - 1] = '\0';
	args = ft_split(line, ' ');
	flag = 0;
	if (!ft_strncmp(args[0], "C", 1) || !ft_strncmp(args[0], "F", 1))
	{
		rgb = ft_split(args[1], ',');
		flag = check_params(rgb);
		if (flag)
			save_rgb(rgb, *args[0]);
		free_dptr(rgb);
	}
	else if (is_texture(args[0]))
	{
		flag = check_params(&args[1]);
		if (flag)
			save_textures(args[0], args[1]);
	}
	free_dptr(args);
	return (flag);
}

int	read_args(char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror(filename);
		close(fd);
		return (0);
	}
	line = get_next_line(fd);
	while (line)
	{
		if (!split_params(line))
		{
			free(line);
			close(fd);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

int	check_params(char **line)
{
	int	i;
	int	atoi;

	if (!line[1])
		return (check_textures(line[0]));
	else
	{
		i = -1;
		while (line[++i])
		{
			atoi = ft_atoi(line[i]);
			if (atoi < 0 || atoi > 255)
				return (0);
		}
	}
	return (1);
}

// TODO : - Verify RGB exists
// TODO : - Verify textures exist
// TODO : - Verify each RGB is declared once
// TODO : - Verify each texture is declared once
// TODO : - Verify map exist, is the last argument and is valid
