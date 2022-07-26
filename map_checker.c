/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:06:04 by gafreita          #+#    #+#             */
/*   Updated: 2022/07/26 19:31:12 by gafreita         ###   ########.fr       */
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
	int		i;

	i = -1;
	while (++i < 3)
		infos()->pec[i] = 0;
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
	if (line == NULL)
		return ;
	if (infos()->map[i + 1] == NULL)
		infos()->width = ft_strlen(line);
	else if (ft_strlen(line) != infos()->width)
		exit_message("Invalid map >> not a rectangule");
	while (line[++j] != '\n' && line)
	{
		if (!(line[j] == '1' || line[j] == '0' || line[j] == 'P'
				|| line[j] == 'C' || line[j] == 'E' || line[j] == 'N'))
			exit_message("Invalid map >> invalid character");
		if ((i == 0 || i == infos()->height - 1
				|| j == 0 || j == infos()->width - 2) && line[j] != '1')
			exit_message("Invalid map >> no border");
		infos()->pec[0] += (line[j] == 'P');
		infos()->pec[1] += (line[j] == 'E');
		infos()->pec[2] += (line[j] == 'C');
		if (infos()->pec[0] == 1 && line[j] == 'P')
		{
			game()->player.x = i;
			game()->player.y = j;
		}
	}
	if ((!infos()->pec[0] || !infos()->pec[1] || !infos()->pec[2]) && i == 0)
		exit_message("Invalid map >> Missing character(s)");
}
