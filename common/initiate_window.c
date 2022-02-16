/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:46:43 by lyaiche           #+#    #+#             */
/*   Updated: 2022/02/16 19:08:01 by lyaiche          ###   ########.fr       */
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
	data->middle = 270 * data->line_bytes + 480;
	// data->start = data->middle - (data->lenght / 2 * data->line_length)
	// 	- (data->width / 2 * data->line_length);
	data->addr[data->middle] = 0x00ff00;
	// draw_tab(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_hook(data->win, 2, 1L << 0, key_hook, data);
	mlx_loop(data->mlx);
}
