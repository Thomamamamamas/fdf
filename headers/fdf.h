/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:37:15 by tcasale           #+#    #+#             */
/*   Updated: 2023/01/06 12:48:38 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WINDOW_LENGHT	10
# define WINDOW_HEIGHT	10

# define KEY_PRESSED	2
# define KEY_RELEASED	3
# define MOUSE_PRESSED	4
# define ON_EXPOSE		12
# define ON_DESTROY		17

# define MOOVE_X		10
# define MOOVE_Y		10

# define CODE_C			8
# define CODE_W			13
# define CODE_S			1
# define CODE_A			0
# define CODE_D			2
# define CODE_RBRACK	30
# define CODE_LBRACK	33
# define CODE_ESC		53

# define WHITE			0x0FFFFFF
# define BLUE_MARINE	0x02803FC
# define BLUE_CLEAR		0x005BCFF
# define BEIGE			0x0E9E199
# define GREEN			0x000FF0D
# define YELLOW			0x0CBFC05
# define RED			0x0E82507
# define PURPLE			0x0EA05FA

# define GRID			100
# define MARGINX		300
# define MARGINY		300

# include "../srcs/mlx/mlx.h"
# include "../srcs/libftprintf/ft_printf.h"
# include "../srcs/libftprintf/libft/libft.h"
# include "../srcs/get_next_line/get_next_line.h"
# include <fcntl.h>
# include <math.h>

typedef struct s_program
{
	float	height;
	float	width;
	int		spacex;
	int		spacey;
	int		error_code;
	float	marginx;
	float	marginy;
	int		grid;
	float	max_height;
	float	max_width;
	float	max_size;
}				t_program;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}				t_rgb;

typedef struct s_v2
{
	float	x;
	float	y;
	t_rgb	color;
}				t_v2;

typedef struct s_v3
{
	float	x;
	float	y;
	float	z;
	t_rgb	color;
}				t_v3;

typedef struct s_colorset
{
	int		color1;
	int		color2;
	int		color3;
	int		color4;
}				t_colorset;

typedef struct s_fdf
{
	t_program	prg;
	void		*mlx;
	void		*win;
	t_v3		**coords;
	t_v2		**mx;
	int			mx_line;
	int			*mx_col;
	float		top;
	float		bottom;
	float		left;
	float		right;
	float		smallest;
	float		medium;
	float		largest;
	t_colorset	colorset;
	int			colorset_id;
}				t_fdf;

//parsing
int			number_of_line(char *file);
void		parse_map(t_fdf *fdf, int fd);
void		allocate_matrix(t_fdf *fdf, char *file);
void		allocate_actual_line(t_fdf *fdf, char *str, int y);
void		parse_windows_info(t_fdf *fdf);
//parsing2
void		parse_actual_line(t_fdf *fdf, char *str, int y);
void		parse_actual_coord(t_fdf *fdf, char *str, int x, int y);
void		actual_coord_to_iso(t_fdf *fdf, int x, int y, int z);
void		convert_coords(t_fdf *fdf);
int			is_hexadecimal_nb(char *str);
//utils
t_fdf		init_fdf(char *file);
void		error_gestion(t_fdf *fdf);
void		get_matrix_limits(t_fdf *fdf);
void		get_matrix_relief(t_fdf *fdf);
//graphic
void		draw_grid(t_fdf *fdf);
void		bresenham_line(t_fdf *fdf, t_v2 coord1, t_v2 coord2);
void		bresenham_base_case(t_fdf *fdf, t_v2 v1, t_v2 v2, t_v2 ev);
void		bresenham_inverse_case(t_fdf *fdf, t_v2 v1, t_v2 v2, t_v2 ev);
void		connect_points(t_fdf *fdf);
//graphic_utils
int			bresenham_increment_v1(int coord1, int coord2);
t_rgb		point_color(t_fdf *fdf, float z);
int			line_color(t_rgb c1, t_rgb c2, float value);
//color
void		get_matrix_colors(t_fdf *fdf);
t_colorset	assign_colorset(int id);
t_rgb		hex_rgb(int value);
int			rgb_hex(t_rgb rgb);
//free
int			end_fdf(t_fdf *fdf);
void		free_2d_char(char **str);
void		free_vector2_array(t_v2 **array, int line);
void		free_vector3_array(t_v3 **array, int line);
// window management
void		init_window(t_fdf *fdf);
void		get_window_size(t_fdf *fdf);
void		get_margins(t_fdf *fdf);
int			try_adapt_grid_size(t_fdf *fdf);
//minilibx fdf
void		change_colorset(t_fdf *fdf);
void		moove_matrix(t_fdf *fdf, int keycode);
int			redraw_matrix(t_fdf *fdf);
int			key_pressed(int code, t_fdf *fdf);
//debug
void		print_vector2(t_v2 vector);
void		print_vector3(t_v3 vector);
void		print_rgb(t_rgb color);
void		print_mx(t_fdf *fdf);
void		print_coords(t_fdf *fdf);
void		print_window_info(t_fdf *fdf);

#endif
