/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:51:31 by psydenst          #+#    #+#             */
/*   Updated: 2022/06/13 20:34:01 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> // APAGA

char	*ft_read_and_save(char *save, int fd)
{
	char	*buffer;
	int 	index;
	int i;

	i = 0;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	index = 1;
	while (buffer[i++] != '\n' && index != 0) // arrumar esse loop pra não ser infinito
	{
		index = read(fd, buffer, BUFFER_SIZE);
		if (index < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[index] = '\0';
		// printf("save no read %s\n", save);
		// printf("buffer no read %s\n", buffer);
		save = ft_strjoin(save, buffer);
	}
	printf("save full %s", save);
	free(buffer);
	return(save);
}

// reads the string until the first \n and gives that value to line. 
char	*get_line(char *save)
{
	int i;
	char *line;
	
	i = 0;
	while (save[i] != '\n')
		i++;
	line = malloc((i + 1) * sizeof(char)); 
	i = 0;
	while (save && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

// save what come's after the \n. 
char	*ft_save_rest(char *save)
{
	int i;
	
	i = 0;
	while (save[i] != '\n')
	{
		i++;	
	}
	return (save + i);
}	

#include <stdio.h> // APAGA
char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (!save)
	{
		save = calloc(1,1);
	}
	//line = NULL;
	save = ft_read_and_save(save, fd);
	//printf("O valor de save é: %s\n", save);
	line = get_line(save);
	save = ft_save_rest(save);
	return (line);

}

#include <fcntl.h>
#include <stdio.h>
int main()
{
	int fd = open("file.txt",  O_RDONLY);
	char *ret;
	int i = 0;
	while (i < 10)
	{
		ret = get_next_line(fd);
		//if (ret[1] == '\0')
		//	break;
		printf("%s", ret);
		free(ret);
		i++;
	}
	close(fd);
}