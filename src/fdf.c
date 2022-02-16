/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:10:51 by lyaiche           #+#    #+#             */
/*   Updated: 2022/02/15 15:21:31 by lyaiche          ###   ########.fr       */
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
	data.lenght = 0;
	data.lenght = 0;
	create_tab(fd, &data);
	stock_map(&data);
	close(fd);
	ft_printtab(&data);
	initiate_window(&data);
}
