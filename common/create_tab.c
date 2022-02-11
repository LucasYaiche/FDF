/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:38:30 by lyaiche           #+#    #+#             */
/*   Updated: 2022/02/10 14:52:15 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_tab(int fd, t_tab *tab)
{
	char	*line;

	line = "";
	while (line != NULL)
	{
		tab->width = row_len(line);
		line = get_next_line(fd);
		if (line)
			tab->lenght++;
	}
	close(fd);
	tab->map = malloc(sizeof(int *) * tab->lenght + 1);
	if (!tab->map)
		panic_button(2, -1, tab);
}
