/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:11:08 by anlima            #+#    #+#             */
/*   Updated: 2023/11/27 19:03:12 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	is_alnum(char *filename);
int	is_empty(char *filename);
int	open_file(char *filename);
int	verify_map(char *filename);
int	check_extension(char *filename, char *extension);

int	is_empty(char *filename)
{
	int		fd;
	int		size;
	char	line[BUFFER_SIZE + 1];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror(filename);
		close(fd);
		return (0);
	}
	size = read(fd, line, BUFFER_SIZE);
	close(fd);
	if (size <= 0)
		return (0);
	return (1);
}

int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror(filename);
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int	verify_map(char *filename)
{
	return (open_file(filename) && is_empty(filename) && is_alnum(filename)
		&& check_extension(filename, ".cub"));
}

int	check_extension(char *filename, char *extension)
{
	char	*temp;

	if (!filename)
		return (0);
	temp = ft_strchr(filename, '.');
	if (temp == NULL)
		return (0);
	if (temp[4] && temp[4] != '\n')
		return (0);
	if (!ft_strncmp(temp, extension, 4) && ft_strlen(filename) > 4)
		return (1);
	return (0);
}

int	is_alnum(char *filename)
{
	int		fd;
	int		flag;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror(filename);
		close(fd);
		return (0);
	}
	line = get_next_line(fd);
	flag = 0;
	while (line)
	{
		if (!flag)
			flag = get_flag(line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (flag)
		return (1);
	return (0);
}
