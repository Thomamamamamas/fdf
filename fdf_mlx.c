/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:16:30 by tcasale           #+#    #+#             */
/*   Updated: 2021/12/22 15:50:24 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_program	init_window(t_parse *parser)
{
	size_t		x;
	size_t		y;
	size_t		n;
	t_program	prog;

	x = 0;
	y = parser->y;
	n = 0;
	while (n < y)
	{
		if (parser->x[n] > x)
			x = parser->x[n];
		n++;
	}
	prog.mlx_ptr = mlx_init();
	prog.win_height = (GRID_SIZEY * 1.75) * y + MARGINY;
	prog.win_width = (GRID_SIZEX * 1.75) * x + MARGINX;
	prog.marginx = prog.win_width / 2 - GRID_SIZEX * 2;
	prog.marginy = MARGINY * y;
	printf("%d\n", prog.marginx);
	if (prog.win_height >= prog.win_width)
		prog.win_midx = prog.win_width / 2;
	else
		prog.win_midx = prog.win_height / 2;
	prog.win_ptr = mlx_new_window(prog.mlx_ptr, prog.win_width, prog.win_height, "FdF");
	return(prog);
}

int	close_window(t_program *prog)
{
	mlx_destroy_window(prog->mlx_ptr, prog->win_ptr);
	exit(0);
	return (-1);
}


int	key_pressed(int keycode, t_program *prog)
{
	if (keycode == KEY_CODE_ESC)
		close_window(prog);
	return (0);
}