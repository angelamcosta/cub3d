/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:02:13 by anlima            #+#    #+#             */
/*   Updated: 2023/12/22 13:17:20 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	keyhooks(int keycode);

int	keyhooks(int keycode)
{
	if (keycode == ESC)
	{
		finish_execution();
		exit(0);
	}
	return (0);
}
