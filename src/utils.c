/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedroso <mpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:17:23 by anlima            #+#    #+#             */
/*   Updated: 2024/01/12 15:20:07 by mpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	clean_mallocs(void);
int		get_flag(char *line);
void	free_dptr(char **str);
void	finish_execution(void);
char	*ft_strjoin_char(char *str, char c);

void	clean_mallocs(void)
{
	free(map()->no);
	free(map()->so);
	free(map()->ea);
	free(map()->we);
	free(win()->north->px_data);
	free(win()->east->px_data);
	free(win()->west->px_data);
	free(win()->south->px_data);
	free(win()->east);
	free(win()->west);
	free(win()->north);
	free(win()->south);
	free_dptr(map()->map);
	free(map()->floor[0]);
	free(map()->floor[1]);
	free(map()->floor[2]);
	free(map()->ceiling[0]);
	free(map()->ceiling[1]);
	free(map()->ceiling[2]);
	free_int_array(win()->pixel_data);
}

int	get_flag(char *line)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	while (line[++i])
	{
		if (!flag && ft_isalnum(line[i]))
			flag = 1;
	}
	return (flag);
}

void	free_dptr(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	if (str)
		free(str);
}

char	*ft_strjoin_char(char *str, char c)
{
	int		i;
	char	*joined;

	i = -1;
	joined = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
	while (str[++i])
		joined[i] = str[i];
	joined[i++] = c;
	joined[i] = '\0';
	return (joined);
}

void	finish_execution(void)
{
	clean_mallocs();
	mlx_clear_window(win()->mlx, win()->mlx_win);
	mlx_destroy_image(win()->mlx, win()->mlx_img->mlx_img);
	mlx_destroy_window(win()->mlx, win()->mlx_win);
	mlx_destroy_display(win()->mlx);
	free(win()->mlx);
	free(win()->mlx_img);
	exit(0);
}
