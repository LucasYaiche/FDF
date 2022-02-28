/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:51:32 by lyaiche           #+#    #+#             */
/*   Updated: 2022/02/28 18:32:04 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(int x, int y, int color, t_data *data)
{
	int	i;

	i = (x * data->bits_per_pixel / 8) + (y * data->line_bytes);
	data->addr[i] = color;
	data->addr[++i] = color >> 8;
	data->addr[++i] = color >> 16;
}

void	perspective(float *x, float *y, int *z, t_data *data)
{	
	*z = data->map[(int)*y][(int)*x];
	*z *= data->zoom;
	*z *= data->height;
	*x *= data->zoom;
	*y *= data->zoom;
	*x = (*x - *y) * cos(data->x_rotate);
	*y = (*x + *y) * sin(data->y_rotate) - *z;
}

void	draw_line(float current_x, float current_y, t_data *data)
{
	float	dx;
	float	dy;
	int		current_z;
	int		next_z;
	int		max;

	perspective(&current_x, &current_y, &current_z, data);
	perspective(&data->next_x, &data->next_y, &next_z, data);
	current_x += 1000 + data->x_step;
	current_y += 100 + data->y_step;
	data->next_x += 1000 + data->x_step;
	data->next_y += 100 + data->y_step;
	dx = data->next_x - current_x;
	dy = data->next_y - current_y;
	max = fmax(fabs(dx), fabs(dy));
	dx /= max;
	dy /= max;
	while ((int)(current_x - data->next_x)
			|| (int)(current_y - data->next_y))
	{
		if (current_x < 1920 && current_y < 1080
			&& current_x > 0 && current_y > 0)
			put_pixel(current_x, current_y, 0xFFFFFF, data);
		current_x += dx;
		current_y += dy;
	}
}

void	draw_tab(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->width)
	{
		j = -1;
		while (++j < data->length)
		{
			if (j < data->length - 1)
			{
				data->next_x = j + 1;
				data->next_y = i;
				draw_line(j, i, data);
			}
			if (i < data->width - 1)
			{
				data->next_x = j;
				data->next_y = i + 1;
				draw_line(j, i, data);
			}
		}	
	}
}
