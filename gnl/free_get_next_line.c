/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatyko <omatyko@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:35:32 by omatyko           #+#    #+#             */
/*   Updated: 2025/03/11 13:09:38 by omatyko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Free memory used by get_next_line if not all data have been read */
void	free_get_next_line(int fd)
{
	char	*temp;

	if (fd < 0)
		return ;
	temp = get_next_line(fd);
	while (temp)
	{
		free(temp);
		temp = get_next_line(fd);
	}
}

void	free_line_close_fd(int fd, char *str)
{
	free(str);
	close(fd);
}

int	free_get_next_line_on_error(int fd, char *line)
{
	free_get_next_line(fd);
	free(line);
	close(fd);
	return (-1);
}
