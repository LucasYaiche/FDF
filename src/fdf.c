/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:10:51 by lyaiche           #+#    #+#             */
/*   Updated: 2022/03/16 15:36:20 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{	
	int			fd;
	t_data		data;

	if (argc != 2)
		panic_button(0, -1, &data);
	data.name = argv[1];
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		panic_button(1, -1, &data);
	create_tab(fd, &data);
	stock_map(&data);
	close(fd);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1920, 1080, data.name);
	data.zoom = fmax(1080 / data.length, 2);
	data.x_step = 700;
	data.y_step = 200;
	data.height = 0.1;
	data.rotate_x = 0;
	data.rotate_y = 0;
	data.orientation_x = 1;
	data.orientation_y = 0.8;
	data.perspect = 1;
	initiate_window(&data);
	mlx_do_key_autorepeaton(data.mlx);
	mlx_hook(data.win, 2, 1L << 0, key_hook, &data);
	mlx_loop(data.mlx);
}
