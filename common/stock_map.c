/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:23:46 by lyaiche           #+#    #+#             */
/*   Updated: 2022/02/10 15:16:32 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	stock_map(char *name, t_tab *tab)
{
	char	*line;
	char	**row;
	int		fd;
	int		i;
	int		j;

	fd = open(name, O_RDONLY);
	if (fd == -1)
		panic_button(1, -1, tab);
	line = "";
	i = -1;
	while (line != NULL)
	{
		++i;
		line = get_next_line(fd);
		if (line)
		{
			row = ft_split(line, ' ');
			if (!row)
				panic_button(3, fd, tab);
			tab->map[i] = malloc(sizeof(int) * (tab->width + 1));
			if (!tab->map[i])
				panic_button(2, -1, tab);
			j = -1;
			while (row[++j])
				tab->map[i][j] = ft_atoi(row[j]);
		}
	}
}
