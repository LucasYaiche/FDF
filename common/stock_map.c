/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:23:46 by lyaiche           #+#    #+#             */
/*   Updated: 2022/02/23 12:05:14 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	stock_map(t_data *data)
{
	char	*line;
	char	**row;
	int		fd;
	int		i;
	int		j;

	fd = open(data->name, O_RDONLY);
	if (fd == -1)
		panic_button(1, -1, data);
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
				panic_button(3, fd, data);
			data->map[i] = malloc(sizeof(int) * (data->length + 1));
			if (!data->map[i])
				panic_button(2, -1, data);
			j = -1;
			while (row[++j])
				data->map[i][j] = ft_atoi(row[j]);
			free(line);
		}
	}
}
