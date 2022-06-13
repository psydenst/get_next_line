/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:49:37 by psydenst          #+#    #+#             */
/*   Updated: 2022/06/13 20:12:01 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // VERIFICAR
#include <stdlib.h> // VERIFICAR

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

typedef struct s_list
{
    char    *content;
    char    *next;
}           t_list;


char	*ft_strjoin(char *s1, char *s2);
int	    ft_strchr (char *str, int c);
size_t	ft_strlen (char *s);
char    *get_next_line(int fd);
char    *ft_read_and_save(char *save, int fd);


#endif
