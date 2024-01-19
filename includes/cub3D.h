/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:09:54 by anlima            #+#    #+#             */
/*   Updated: 2024/01/19 15:10:15 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define ARG_ERROR "Invalid arguments!\nUsage => ./cub3D <.cub_file>\n"
# include "../mlx/mlx.h"
# include "get_next_line.h"
# include "libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# define NORTH 1
# define SOUTH 2
# define EAST 3
# define WEST 4
# define ESC 65307
# define IMG_SIZE 64
# define WIDTH 640
# define HEIGHT 640
# define SPEED 0.05
# define ROT 0.045

typedef struct s_keys
{
	int		w;
	int		a;
	int		s;
	int		d;
	int		left;
	int		right;
}			t_keys;

typedef struct s_coord
{
	double	x;
	double	y;
}			t_coord;

typedef struct s_pos
{
	int		hit;
	int		side;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		draw_end;
	int		draw_start;
	int		line_height;
	double	cam_x;
	double	wall_x;
	double	prep_wall_dist;
	t_coord	dir;
	t_coord	plane;
	t_coord	ray_dir;
	t_coord	side_dist;
	t_coord	delta_dist;
	t_coord	pos;
}			t_pos;

typedef struct s_img
{
	void	*mlx_img;
	int		bpp;
	int		pos_x;
	int		pos_y;
	int		width;
	int		height;
	int		endian;
	int		line_len;
	int		*addr;
	int		*px_data;
	double	img_pos;
	double	img_step;
}			t_img;

typedef struct s_map
{
	int		rows;
	int		cols;
	char	player;
	t_coord	pos;
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	char	*floor[3];
	char	*ceiling[3];
	char	**map;
}			t_map;

typedef struct s_win
{
	int		**pixel_data;
	void	*mlx;
	void	*mlx_win;
	t_img	*north;
	t_img	*south;
	t_img	*east;
	t_img	*west;
	t_img	*mlx_img;
	t_keys	keys;
}			t_win;

typedef struct s_line
{
	int		x;
	int		y;
	int		y0;
	int		y1;
	int		tex_x;
	int		tex_y;
}			t_line;

// flood_fill
void		set_row_col(void);
int			mark_regions(void);
int			is_map_closed(void);
int			is_valid_char(char c);
void		dfs(int row, int col, char mark);
// map_args
int			is_filled(void);
int			save_map(char *line);
int			split_params(char *line);
int			read_args(char *filename);
int			check_params(char **line);
// map_parser
int			is_alnum(char *filename);
int			is_empty(char *filename);
int			open_file(char *filename);
int			verify_map(char *filename);
int			check_extension(char *filename, char *extension);
// parser_utils
int			is_valid_path(void);
int			is_valid_str(char *str);
int			check_char(int i, int j);
// rgb
int			check_rgb(char **args);
void		save_rgb(char **rgb, char pos);
// textures
int			is_texture(char *pos);
int			check_textures(char *filename);
int			save_textures(char *pos, char *texture);
// utils
int			get_max_len(void);
void		set_player(int row, int col, char mark);
// imgs
void		init_texture(void);
int			**create_pixel_data(void);
// raycaster
int			render(void);
// scaling
void		dda(void);
void		step(void);
void		prep_draw_line(void);
void		camera_distance(void);
t_img		*select_texture(void);
// utils (raycaster)
void		set_camera(void);
void		apply_texture(t_img *img, int x);
// win general
int			close_win_x(t_win	*win);
// hooks
int			rotate(int i);
t_coord		get_temp_pos(char dir);
int			move(char dir, int flag);
int			keyhooks_press(int keycode);
int			keyhooks_release(int keycode);
// structs
void		set_images(void);
// general
t_map		*map(void);
t_pos		*pos(void);
t_win		*win(void);
void		free_images(void);
void		exec_free(void *ptr);
// utils
void		clean_mallocs(void);
int			get_flag(char *line);
void		free_dptr(char **str);
void		finish_execution(void);
char		*ft_strjoin_char(char *str, char c);
// utils 2
void		set_pos(int x);
void		allocate_imgs(void);
void		init_instance(void);
void		close_win_error(void);
void		free_int_array(int **arr);

#endif