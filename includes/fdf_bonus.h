/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:23:59 by lyaiche           #+#    #+#             */
/*   Updated: 2022/03/17 16:01:34 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "fdf.h"

int		key_hook_bonus(int keycode, t_data *data);
void	draw_tab_bonus(t_data *data);
void	initiate_window_bonus(t_data *data);
int		color(t_data *data);

#endif