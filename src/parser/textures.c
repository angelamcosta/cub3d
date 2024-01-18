/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:23:02 by anlima            #+#    #+#             */
/*   Updated: 2024/01/18 17:42:57 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	is_texture(char *pos);
int	check_textures(char *filename);
int	save_textures(char *pos, char *texture);

int	is_texture(char *pos)
{
	return (!ft_strncmp(pos, "NO", 2) || !ft_strncmp(pos, "SO", 2)
		|| !ft_strncmp(pos, "EA", 2) || !ft_strncmp(pos, "WE", 2));
}

int	check_textures(char *filename)
{
	if (!check_extension(&filename[1], ".xpm"))
	{
		write(2, "error while checking extension\n", 32);
		return (0);
	}
	if (!is_alnum(filename))
	{
		write(2, "error invalid char\n", 20);
		return (0);
	}
	if (!is_empty(filename))
	{
		write(2, "error file empty\n", 18);
		return (0);
	}
	if (!open_file(filename))
	{
		write(2, "error trying to open the file\n", 31);
		return (0);
	}
	return (1);
}

int	save_textures(char *pos, char *texture)
{
	if (!ft_strncmp(pos, "NO", 2) && !map()->no)
		map()->no = ft_strdup(texture);
	else if (!ft_strncmp(pos, "SO", 2) && !map()->so)
		map()->so = ft_strdup(texture);
	else if (!ft_strncmp(pos, "EA", 2) && !map()->ea)
		map()->ea = ft_strdup(texture);
	else if (!ft_strncmp(pos, "WE", 2) && !map()->we)
		map()->we = ft_strdup(texture);
	else
		return (0);
	return (1);
}
