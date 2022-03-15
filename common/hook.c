/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:01:24 by lyaiche           #+#    #+#             */
/*   Updated: 2022/03/15 17:37:04 by lyaiche          ###   ########.fr       */
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
		data->height += 0.01;
	if (keycode == 27)
		data->height -= 0.01;
	if (keycode == 0)
		data->rotate += 0.05;
	if (keycode == 2)
		data->rotate -= 0.05;
	if (keycode == 29)
		data->zoom += 2;
	if (keycode == 25)
		if (!(data->zoom == 1))
			data->zoom -= 2;
	mlx_clear_window(data->mlx, data->win);
	initiate_window(data);
	return (0);
}
