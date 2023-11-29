/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:23:02 by anlima            #+#    #+#             */
/*   Updated: 2023/11/29 16:05:18 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int		is_texture(char *pos);
int		check_textures(char *filename);
void	save_textures(char *pos, char *texture);

int	is_texture(char *pos)
{
	return (!ft_strncmp(pos, "NO", 2) || !ft_strncmp(pos, "SO", 2)
		|| !ft_strncmp(pos, "EA", 2) || !ft_strncmp(pos, "WE", 2));
}

// TODO : - Check extension needs to consider relative/absolute paths

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

// int	check_textures(char *filename)
// {
// 	if (!check_extension(&filename[1], ".xpm"))
// 		return (0);
// 	return (1);
// }

void	save_textures(char *pos, char *texture)
{
	if (!ft_strncmp(pos, "NO", 2))
		map()->no = ft_strdup(texture);
	else if (!ft_strncmp(pos, "SO", 2))
		map()->so = ft_strdup(texture);
	else if (!ft_strncmp(pos, "EA", 2))
		map()->ea = ft_strdup(texture);
	else if (!ft_strncmp(pos, "WE", 2))
		map()->we = ft_strdup(texture);
}
