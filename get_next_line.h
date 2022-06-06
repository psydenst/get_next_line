/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:39:05 by psydenst          #+#    #+#             */
/*   Updated: 2022/06/06 20:19:37 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

typedef struct s_list
{
    char    *content;
    struct s_list   *next;
} t_list;

#endif