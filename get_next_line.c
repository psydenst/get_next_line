/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:51:31 by psydenst          #+#    #+#             */
/*   Updated: 2022/06/14 18:57:15 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> // APAGA

char	*ft_read_and_save(char *save, int fd)
{
	char	*buffer;
	int		index;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	index = 1;
	while (!ft_strchr(save, '\n') && index != 0)
	{
		index = read(fd, buffer, BUFFER_SIZE);
		if (index == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[index] = '\0';
		save = ft_strjoin(save, buffer);
	}
	free (buffer);
	return (save);
}

// reads the string until the first \n and gives that value to line. 
char	*get_line(char *save)
{
	int		i;
	char	*line;

	i = 0;
	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

// save what come's after the \n.
char	*ft_save_rest(char *save)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free (save);
		return (NULL);
	}
	ret = malloc((ft_strlen(save) - i + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	j = 0;
	i = i + 1;
	while (save[i] != '\0')
		ret[j++] = save[i++];
	ret[j] = '\0';
	free (save);
	return (ret);
}	

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = ft_read_and_save(save, fd);
	if (!save)
		return (NULL);
	line = get_line(save);
	save = ft_save_rest(save);
	return (line);
}

// #include <fcntl.h>
// #include <stdio.h>
// int main()
// {
// 	int fd = open("file.txt",  O_RDONLY);
// 	printf("%i\n", fd);
// 	char *ret;
// 	int i = 0;
// 	while (i <= 30)
// 	{
// 		ret = get_next_line(fd);
// 		printf("%s", ret);
// 		free(ret);
// 		i++;
// 	}
// 	close(fd);
// }
