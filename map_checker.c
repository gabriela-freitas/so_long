/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:06:04 by gafreita          #+#    #+#             */
/*   Updated: 2022/07/25 18:56:41 by gafreita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_map(char *line, int i, int j);
static void	fill_map(int fd, int i);

/*Check if its a valid file name and a valid map
And saves the map*/
void	parse_map(char *file_name)
{
	int		fd;

	if (ft_strncmp(ft_strrchr(file_name, '.'), ".ber\0", 6))
		exit_message("Invalid file name");
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit_message("Map file not found");
	fill_map(fd, 0);
}

/*Read from the file and fill the map (char **) recursively*/
static void	fill_map(int fd, int i)
{
	char	*line;

	line = get_next_line(fd);
	if (line)
		fill_map(fd, i + 1);
	else
	{
		infos()->height = i;
		infos()->map = malloc(sizeof(char *) * (i + 1));
		if (!infos()->map)
			exit_message("Malloc error");
	}
	infos()->map[i] = line;
	check_map(line, i, -1);
}

/*Check if is a valid map:
Has at least 1 Collectable, 1 Start Position and 1 Exit
Is a rectangule
Is surrounded by borders
Has only the following: C, E, P, 0, 1*/
static void	check_map(char *line, int i, int j)
{
	static int	p = 0;
	static int	e = 0;
	static int	c = 0;

	if (line == NULL)
		return ;
	if (infos()->map[i + 1] == NULL)
		infos()->width = ft_strlen(line);
	else if (ft_strlen(line) != infos()->width)
		exit_message("Invalid map >> not a rectangule");
	while (line[++j] != '\n' && line)
	{
		if (!(line[j] == '1' || line[j] == '0' || line[j] == 'P'
				|| line[j] == 'C' || line[j] == 'E'))
			exit_message("Invalid map >> invalid character");
		if ((i == 0 || i == infos()->height - 1
				|| j == 0 || j == infos()->width - 2) && line[j] != '1')
			exit_message("Invalid map >> no border");
		p += (line[j] == 'P');
		e += (line[j] == 'E');
		c += (line[j] == 'C');
		if (p == 1 && line[j] == 'P')
		{
			infos()->player.x = j;
			infos()->player.y = i;
		}
	}
	if ((!p || !e || !c) && i == 0)
		exit_message("Invalid map >> Missing character(s)");
}
