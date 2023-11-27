/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:10:10 by anlima            #+#    #+#             */
/*   Updated: 2023/11/27 19:06:39 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	split_params(char *line);
int	read_args(char *filename);
int	check_params(char **line);
int	check_textures(char *filename);

int	split_params(char *line)
{
	int		i;
	int		flag;
	char	**rgb;
	char	**args;

	args = ft_split(line, ' ');
	flag = 0;
	if (!args[2])
	{
		if (!ft_strncmp(args[0], "C", 1) || !ft_strncmp(args[0], "F", 1))
		{
			rgb = ft_split(args[1], ',');
			flag = check_params(rgb);
			i = -1;
			free_dptr(rgb);
		}
		else
			flag = check_params(&args[1]);
	}
	i = -1;
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

	if (!line[1])
		return (check_textures(line[0]));
	else
	{
		i = -1;
		while (line[++i])
		{
			if (ft_atoi(line[i]) < 0 || ft_atoi(line[i]) > 255)
				return (0);
		}
	}
	return (1);
}

int	check_textures(char *filename)
{
	if (!check_extension(&filename[1], ".xpm") || !open_file(filename)
		|| !is_empty(filename) || !is_alnum(filename))
		return (0);
	return (1);
}

// TODO : - Verify textures exist, are .xpm, are declared once and are valid
// TODO : - Verify RGB exists and is valid
// TODO : - Verify map exist, is the last argument and is valid
