/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:27:05 by gafreita          #+#    #+#             */
/*   Updated: 2022/07/26 23:40:44 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
