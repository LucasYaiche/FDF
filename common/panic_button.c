/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panic_button.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:11:09 by lyaiche           #+#    #+#             */
/*   Updated: 2022/03/18 15:25:44 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	panic_button(int error, int fd, t_data *data)
{
	if (error == 0)
		write(2, "arguments error.\n", 17);
	else if (error == 1)
		write(2, "error file descriptor.\n", 23);
	else if (error == 2)
		write(2, "malloc error.\n", 14);
	else if (error == 3)
	{
		write(2, "ft_split error.\n", 16);
		close(fd);
	}
	else if (error == 4)
	{
		free_tab(data);
		write(1, "Fin du programme.\n", 18);
		exit(0);
	}
	exit(1);
}
