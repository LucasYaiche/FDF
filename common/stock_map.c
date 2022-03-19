/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:23:46 by lyaiche           #+#    #+#             */
/*   Updated: 2022/03/19 17:46:14 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_row(char **row, int len)
{
	while (len > 0)
		ft_free_char(&row[--len]);
	free(row);
	row = NULL;
}

void	stock_map_3(char **row, int i, int fd, t_data *data)
{
	int	j;

	data->map[i] = malloc(sizeof(int) * (data->length + 1));
	if (!data->map[i])
	{
		free_tab(data);
		close(fd);
		panic_button(2, -1, data);
	}
	j = -1;
	while (row[++j])
		data->map[i][j] = ft_atoi(row[j]);
	free_row(row, j);
}

void	stock_map_2(int fd, char *line, t_data *data)
{
	int		i;
	char	**row;

	i = -1;
	while (line != NULL)
	{
		++i;
		line = get_next_line(fd);
		if (line)
		{
			row = ft_split(line, ' ');
			free(line);
			if (!row)
				panic_button(3, fd, data);
			stock_map_3(row, i, fd, data);
		}
	}
}

void	stock_map(t_data *data)
{
	char	*line;
	int		fd;

	fd = open(data->name, O_RDONLY);
	if (fd == -1)
		panic_button(1, -1, data);
	line = "";
	stock_map_2(fd, line, data);
	close(fd);
}
