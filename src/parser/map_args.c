/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:10:10 by anlima            #+#    #+#             */
/*   Updated: 2023/12/04 21:30:03 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	is_filled(void);
int	save_map(char *line);
int	split_params(char *line);
int	read_args(char *filename);
int	check_params(char **line);

int	is_filled(void)
{
	if (!map()->no || !map()->so || !map()->ea || !map()->we)
		return (0);
	if (!map()->floor[0] || !map()->floor[1] || !map()->floor[2])
		return (0);
	if (!map()->ceiling[0] || !map()->ceiling[1] || !map()->ceiling[2])
		return (0);
	return (1);
}

int	split_params(char *line)
{
	int		flag;
	char	**args;

	if (*line == '\n' && !map()->map)
		return (1);
	else if (*line == '\n')
		return (0);
	flag = ft_strlen(line) - 1;
	if (line && line[flag] == '\n')
		line[flag] = '\0';
	flag = 0;
	if (!is_filled())
	{
		args = ft_split(line, ' ');
		if (!ft_strncmp(args[0], "C", 1) || !ft_strncmp(args[0], "F", 1))
			flag = check_rgb(args);
		else if (is_texture(args[0]))
		{
			flag = check_params(&args[1]);
			if (flag)
				save_textures(args[0], args[1]);
		}
		free_dptr(args);
	}
	else if (is_valid_str(line))
		flag = save_map(line);
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

int	save_map(char *line)
{
	int		i;
	char	**copy;

	i = 0;
	while (map()->map && map()->map[i])
		i++;
	copy = (char **)malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (map()->map && map()->map[i])
	{
		copy[i] = ft_strdup(map()->map[i]);
		i++;
	}
	copy[i] = ft_strdup(line);
	copy[++i] = 0;
	map()->rows++;
	if (map()->map)
		free_dptr(map()->map);
	map()->map = copy;
	return (1);
}
