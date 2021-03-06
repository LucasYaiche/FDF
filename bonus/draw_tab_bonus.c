/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tab_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:51:32 by lyaiche           #+#    #+#             */
/*   Updated: 2022/03/17 17:22:41 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	put_pixel_bonus(int x, int y, int color, t_data *data)
{
	int	i;

	i = (x * data->bits_per_pixel / 8) + (y * data->line_bytes);
	data->addr[i] = color;
	data->addr[++i] = color >> 8;
	data->addr[++i] = color >> 16;
}

void	perspective_bonus(float *x, float *y, int *z, t_data *data)
{	
	int	temp_x;
	int	temp_y;

	*z = data->map[(int)*y][(int)*x];
	*z *= data->zoom;
	*z *= data->height;
	*x *= data->zoom;
	*y *= data->zoom;
	temp_x = *x;
	temp_y = *y;
	if (data->perspect)
	{
		*x = temp_x * cos(data->rotate_x)
			- temp_y * sin(data->rotate_y);
		*y = temp_x * sin(data->rotate_x)
			+ temp_y * cos(data->rotate_y);
		*x = (*x - *y) * cos(data->orientation_x);
		*y = (*x + *y) * sin(data->orientation_x) - *z * cos(data->rotate_y);
	}
}

void	draw_line_bonus_2(float current_x, float current_y, t_data *data)
{
	float	dx;
	float	dy;
	int		max;

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
			put_pixel_bonus(current_x, current_y, color(data), data);
		current_x += dx;
		current_y += dy;
	}
}

void	draw_line_bonus(float current_x, float current_y, t_data *data)
{
	int		current_z;
	int		next_z;

	perspective_bonus(&current_x, &current_y, &current_z, data);
	perspective_bonus(&data->next_x, &data->next_y, &next_z, data);
	current_x += data->x_step;
	current_y += data->y_step;
	data->next_x += data->x_step;
	data->next_y += data->y_step;
	draw_line_bonus_2(current_x, current_y, data);
}

void	draw_tab_bonus(t_data *data)
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
				draw_line_bonus(j, i, data);
			}
			if (i < data->width - 1)
			{
				data->next_x = j;
				data->next_y = i + 1;
				draw_line_bonus(j, i, data);
			}
		}	
	}
}
