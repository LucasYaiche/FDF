/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:01:24 by lyaiche           #+#    #+#             */
/*   Updated: 2022/03/18 15:34:42 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	key_hook_bonus_5(int keycode, t_data *data)
{
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
	if (keycode == 1)
		if (data->rotate_y > -60)
			data->rotate_y -= 0.05;
	if (keycode == 0)
		if (data->rotate_x < 60)
			data->rotate_x += 0.05;
	if (keycode == 2)
		if (data->rotate_x > -60)
			data->rotate_x -= 0.05;
}

void	key_hook_bonus_4(int keycode, t_data *data)
{
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
	key_hook_bonus_5(keycode, data);
}

void	key_hook_bonus_3(int keycode, t_data *data)
{
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
	if (keycode == 13)
		if (data->rotate_y < 60)
			data->rotate_y += 0.05;
	if (keycode == 14)
	{
		if (data->rotate_x < 60
			&& data->rotate_y < 60)
		{
			data->rotate_x += 0.05;
			data->rotate_y += 0.05;
		}
	}
	key_hook_bonus_4(keycode, data);
}

void	key_hook_bonus_2(int keycode, t_data *data)
{
	if (keycode == 27)
		if (data->height > -100)
			data->height -= 0.02;
	if (keycode == 12)
	{
		if (data->rotate_x > -60
			&& data->rotate_y > -60)
		{
			data->rotate_x -= 0.05;
			data->rotate_y -= 0.05;
		}
	}
	if (keycode == 29)
		if (data->zoom < 500)
			data->zoom += 1;
	if (keycode == 25)
		if (!(data->zoom == 1))
			data->zoom -= 1;
	key_hook_bonus_3(keycode, data);
}

int	key_hook_bonus(int keycode, t_data *data)
{
	if (keycode == 53)
		end(data);
	if (keycode == 124)
		if (data->x_step < 10000)
			data->x_step += 15;
	if (keycode == 123)
		if (data->x_step > -10000)
			data->x_step -= 15;
	if (keycode == 125)
		if (data->y_step < 10000)
			data->y_step += 15;
	if (keycode == 126)
		if (data->y_step > -10000)
			data->y_step -= 15;
	if (keycode == 24)
		if (data->height < 100)
			data->height += 0.02;
	key_hook_bonus_2(keycode, data);
	mlx_clear_window(data->mlx, data->win);
	initiate_window_bonus(data);
	return (0);
}
