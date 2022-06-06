/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:48:49 by psydenst          #+#    #+#             */
/*   Updated: 2022/06/06 20:46:42 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static t_list   *stash = NULL; // *content and *next
    char            *line;
    int             had_read;

    if (fd < 0 || BUFFER_SIZE <= 0 || read (fd, &line, 0) < 0) // a última condição só verifica se um arquivo é lisível.
        return NULL; 
    had_read = 1;
    line = NULL;
    // 1. read from fd and add to linked list
    read_it(fd, &stash, &had_read);
    // 2. extract from stash to line
    // 3. clean up stash
    
    return (line);
}

void read_it(int fd, t_list **stash, int *had_read) // I'm passing the adresses of the variables (&stash and &had_read), so they became pointers. 
{
        char    *buffer;
        
        while(!found_newline(*stash) && *had_read != 0)
        {
            buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1)); // allocating the space
            if (!buffer)
                return (NULL);
            *had_read = read(fd, buffer, BUFFER_SIZE);
            if((*stash == NULL && *had_read == 0) || *had_read == -1)
            {
                free(buffer);
                return;
            }
            buffer[*had_read] = '\0'; // read não coloca o \0 do final. Um dim de linha não é usado.
            copy_it(stash, buffer, had_read);
            free(buffer);
        }
}

void    copy_it(t_list **stash, char *buffer, int had_read)
{ // this function will copy the content of the line read - stored in buffer - to the last element of stash. 
    int i;
    t_list  *current;
    t_list  *new_node;

    new_node = malloc(sizeof(t_list));
    if(new_node == NULL)
        return;
    new_node->next = NULL;
    new_node->content = malloc(sizeof(char) * (had_read + 1));
    if(new_node->content == NULL)
        return;
    i = 0;
    while(buffer[i] && i < had_read)
    {
        new_node->content[i] = buffer[i] // makes the copy to new_node
        i++;
    }
    ft_lstadd_back(stash, new_node); // add new_node in the end of the list.
}
        
        
        

