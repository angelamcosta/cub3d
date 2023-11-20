/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:11:08 by anlima            #+#    #+#             */
/*   Updated: 2023/11/20 17:31:01 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	check_extension(char *filename)
{
	char *temp;

	temp = ft_strchr(filename, '.');
	if (temp == NULL)
		return (0);
	if (!ft_strncmp(temp, ".cub", 4) && ft_strlen(temp) == 4)
		return (1);
	return (0);
}
