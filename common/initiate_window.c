/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:46:43 by lyaiche           #+#    #+#             */
/*   Updated: 2022/02/18 12:00:34 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initiate_window(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1920, 1080, data->name);
	data->img = mlx_new_image(data->mlx, 1920, 1080);
	data->addr = (int *)mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_bytes, &data->endian);
	data->line_bytes /= 4;
	data->init_x = 960 - (data->length / 2) * 16;
	data->init_y = 540 - (data->width / 2) * 9;
	data->addr[data->init_y * data->line_bytes + data->init_x] = 0xffffff;
	data->init_x = 960;
	data->init_y = 540;
	data->addr[data->init_y * data->line_bytes + data->init_x] = 0xffffff;
	draw_tab(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_hook(data->win, 2, 1L << 0, key_hook, data);
	mlx_loop(data->mlx);
}
