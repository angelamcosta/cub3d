/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedroso <mpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:02:13 by anlima            #+#    #+#             */
/*   Updated: 2024/01/15 00:00:48 by mpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int		rotate(int i);
t_coord	get_temp_pos(char dir);
int		move(char dir, int flag);
int		keyhooks_press(int keycode);
int		keyhooks_release(int keycode);

int	keyhooks_press(int keycode)
{
	if (keycode == XK_Escape)
	{
		finish_execution();
		exit(0);
	}
	if (keycode == XK_w)
		win()->keys.w = 1;
	if (keycode == XK_a)
		win()->keys.a = 1;
	if (keycode == XK_s)
		win()->keys.s = 1;
	if (keycode == XK_d)
		win()->keys.d = 1;
	if (keycode == XK_Left)
		win()->keys.left = 1;
	if (keycode == XK_Right)
		win()->keys.right = 1;
	render();
	return (0);
}

int	keyhooks_release(int keycode)
{
	if (keycode == XK_w)
		win()->keys.w = 0;
	if (keycode == XK_a)
		win()->keys.a = 0;
	if (keycode == XK_s)
		win()->keys.s = 0;
	if (keycode == XK_d)
		win()->keys.d = 0;
	if (keycode == XK_Left)
		win()->keys.left = 0;
	if (keycode == XK_Right)
		win()->keys.right = 0;
	render();
	return (0);
}

int	move(char dir, int flag)
{
	t_coord	temp;

	temp = get_temp_pos(dir);
	if (map()->map[(int)floor(temp.y)][(int)floor(temp.x)] == '1')
		return (0);
	if (dir == 'W' || dir == 'S')
	{
		if (map()->map[(int)(pos()->pos.y + pos()->dir.y
				* SPEED)][(int)pos()->pos.x] != '1')
			pos()->pos.y += pos()->dir.y * SPEED * flag;
		if (map()->map[(int)pos()->pos.y][(int)(pos()->pos.x + pos()->dir.x
				* SPEED)] != '1')
			pos()->pos.x += pos()->dir.x * SPEED * flag;
	}
	else
	{
		if (map()->map[(int)(pos()->pos.y + pos()->plane.y
				* SPEED)][(int)pos()->pos.x] != '1')
			pos()->pos.y += pos()->plane.y * SPEED * flag;
		if (map()->map[(int)pos()->pos.y][(int)(pos()->pos.x + pos()->plane.x
				* SPEED)] != '1')
			pos()->pos.x += pos()->plane.x * SPEED * flag;
	}
	map()->pos.x = temp.x;
	map()->pos.y = temp.y;
	return (1);
}

int	rotate(int i)
{
	double	dir_x;
	double	plane_x;

	dir_x = pos()->dir.x;
	plane_x = pos()->plane.x;
	pos()->dir.x = pos()->dir.x * cos(i * ROT) - pos()->dir.y * sin(i
			* ROT);
	pos()->dir.y = dir_x * sin(i * ROT) + pos()->dir.y * cos(i * ROT);
	pos()->plane.x = pos()->plane.x * cos(i * ROT) - pos()->plane.y * sin(i
			* ROT);
	pos()->plane.y = plane_x * sin(i * ROT) +
		pos()->plane.y * cos(i * ROT);
	return (1);
}

t_coord	get_temp_pos(char dir)
{
	t_coord	temp;

	if (dir == 'W')
	{
		temp.x = map()->pos.x + pos()->dir.x * SPEED;
		temp.y = map()->pos.y + pos()->dir.y * SPEED;
	}
	else if (dir == 'S')
	{
		temp.x = map()->pos.x - pos()->dir.x * SPEED;
		temp.y = map()->pos.y - pos()->dir.y * SPEED;
	}
	else if (dir == 'D')
	{
		temp.x = map()->pos.x + pos()->plane.x * SPEED;
		temp.y = map()->pos.y + pos()->plane.y * SPEED;
	}
	else
	{
		temp.x = map()->pos.x - pos()->plane.x * SPEED;
		temp.y = map()->pos.y - pos()->plane.y * SPEED;
	}
	return (temp);
}
