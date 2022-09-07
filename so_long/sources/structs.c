/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:27:05 by gafreita          #+#    #+#             */
/*   Updated: 2022/09/07 14:27:48 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*initializes variables to 0*/
void	init_variables(void)
{
	int		i;

	i = -1;
	while (++i < 3)
		infos()->pec[i] = 0;
	game()->steps = 0;
	game()->collects = 0;
}

/*contains information about the mlx pointers and windows*/
t_so_long	*infos(void)
{
	static t_so_long	infos;

	return (&infos);
}

/*Has all the images pointers*/
t_images	*img(void)
{
	static t_images	img;

	return (&img);
}

/*stores the game's current state*/
t_game	*game(void)
{
	static t_game	game;

	return (&game);
}
