/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:27:05 by gafreita          #+#    #+#             */
/*   Updated: 2022/07/26 21:28:37 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_so_long	*infos(void)
{
	static t_so_long	infos;

	return (&infos);
}

t_images	*img(void)
{
	static t_images	img;

	return (&img);
}

t_game	*game(void)
{
	static t_game	game;

	return (&game);
}
