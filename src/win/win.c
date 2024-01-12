/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:02:22 by anlima            #+#    #+#             */
/*   Updated: 2024/01/12 14:00:59 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	convert_rgb(void);
int		encode_rgb(uint8_t red, uint8_t green, uint8_t blue);

int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

void	convert_rgb(void)
{
	int	floor[3];
	int	ceiling[3];

	floor[0] = ft_atoi(map()->floor[0]);
	floor[1] = ft_atoi(map()->floor[1]);
	floor[2] = ft_atoi(map()->floor[2]);
	ceiling[0] = ft_atoi(map()->ceiling[0]);
	ceiling[1] = ft_atoi(map()->ceiling[1]);
	ceiling[2] = ft_atoi(map()->ceiling[2]);
	(win()->ceiling) = encode_rgb(ceiling[0], ceiling[1], ceiling[2]);
	(win()->floor) = encode_rgb(floor[0], floor[1], floor[2]);
	printf("ceiling => %i\tfloor => %i\n", win()->ceiling, win()->floor);
}
