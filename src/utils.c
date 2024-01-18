/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:17:23 by anlima            #+#    #+#             */
/*   Updated: 2024/01/18 18:04:29 by anlima           ###   ########.fr       */
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
	exec_free(map()->floor[0]);
	exec_free(map()->floor[1]);
	exec_free(map()->floor[2]);
	exec_free(map()->ceiling[0]);
	exec_free(map()->ceiling[1]);
	exec_free(map()->ceiling[2]);
	exec_free(map()->no);
	exec_free(map()->so);
	exec_free(map()->ea);
	exec_free(map()->we);
	free_images();
	exec_free(win()->east);
	exec_free(win()->west);
	exec_free(win()->north);
	exec_free(win()->south);
	if (map()->map)
		free_dptr(map()->map);
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
		exec_free(str[i]);
	if (str)
		free(str);
	str = NULL;
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
