/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:10:51 by lyaiche           #+#    #+#             */
/*   Updated: 2022/02/10 17:45:27 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{	
	int			fd;
	t_tab		tab;

	if (argc != 2)
		panic_button(0, -1, &tab);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		panic_button(1, -1, &tab);
	tab.lenght = 0;
	tab.lenght = 0;
	create_tab(fd, &tab);
	stock_map(argv[1], &tab);
	initiate_window(&tab);
}
