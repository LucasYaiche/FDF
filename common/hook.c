/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:01:24 by lyaiche           #+#    #+#             */
/*   Updated: 2022/03/17 14:01:39 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		write(1, "Fin du programme.\n", 18);
		end(data);
	}
	if (keycode == 124)
		data->x_step += 15;
	if (keycode == 123)
		data->x_step -= 15;
	if (keycode == 125)
		data->y_step += 15;
	if (keycode == 126)
		data->y_step -= 15;
	if (keycode == 24)
		data->height += 0.02;
	if (keycode == 27)
		data->height -= 0.02;
	if (keycode == 13)
		data->rotate_y += 0.05;
	if (keycode == 1)
		data->rotate_y -= 0.05;
	if (keycode == 0)
		data->rotate_x += 0.05;
	if (keycode == 2)
		data->rotate_x -= 0.05;
	if (keycode == 14)
	{
		data->rotate_x += 0.05;
		data->rotate_y += 0.05;
	}
	if (keycode == 12)
	{
		data->rotate_x -= 0.05;
		data->rotate_y -= 0.05;
	}
	if (keycode == 29)
		data->zoom += 1;
	if (keycode == 25)
		if (!(data->zoom == 1))
			data->zoom -= 1;
	if (keycode == 18)
	{
		data->rotate_x = 0;
		data->rotate_y = 0;
		data->height = 0.1;
		data->x_step = 900;
		data->y_step = 200;
		data->zoom = fmax(1080 / data->length, 2);
		data->orientation_x = 1;
		data->orientation_y = 0.8;
		data->perspect = 1;
	}	
	if (keycode == 19)
	{
		data->rotate_x = 1;
		data->rotate_y = 0;
		data->height = 0.1;
		data->x_step = 900;
		data->y_step = 200;
		data->zoom = fmax(1080 / data->length, 2);
		data->orientation_x = 0;
		data->orientation_y = 0.8;
		data->perspect = 1;
	}	
	if (keycode == 20)
	{
		data->rotate_x = 0;
		data->rotate_y = 0;
		data->height = 0.1;
		data->x_step = 900;
		data->y_step = 200;
		data->zoom = fmax(1080 / data->length, 2);
		data->orientation_x = 0;
		data->orientation_y = 0;
		data->perspect = 0;
	}
	if (keycode == 21)
	{
		data->rotate_x = -0.7;
		data->rotate_y = 0.55;
		data->height = 0.1;
		data->x_step = 900;
		data->y_step = 200;
		data->zoom = fmax(1080 / data->length, 2);
		data->orientation_x = 1;
		data->orientation_y = 0.8;
		data->perspect = 1;
	}
	if (keycode == 8)
		data->color++;
	mlx_clear_window(data->mlx, data->win);
	initiate_window(data);
	return (0);
}
