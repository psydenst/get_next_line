/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:46:39 by psydenst          #+#    #+#             */
/*   Updated: 2022/06/06 20:37:50 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

int found_newline(t_list *stash)
{
    int i;
    t_list *current;

    if (stash == NULL)
        return (0);
    current = ft_lst_get_last(stash) // go to the last node of the list
    i = 0;
    
    while(current->content[i]) // search each character of the .content of the node and tell me if it is a newline or not. 
    {
        if(current->content[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*joker;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	joker = ft_lstlast(*lst);
	joker->next = new;
}

