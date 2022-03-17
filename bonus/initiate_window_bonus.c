/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_window_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:46:43 by lyaiche           #+#    #+#             */
/*   Updated: 2022/03/17 17:02:54 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	initiate_window_bonus(t_data *data)
{
	data->img = mlx_new_image(data->mlx, 1920, 1080);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_bytes, &data->endian);
	draw_tab_bonus(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0,
		0);
}
