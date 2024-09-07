/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:18:24 by ousabbar          #+#    #+#             */
/*   Updated: 2023/11/04 17:18:28 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*s;

	s = *lst;
	if (s && del)
	{
		while (s)
		{
			s = s->next;
			ft_lstdelone(*lst, del);
			*lst = s;
		}
		*lst = NULL;
	}
}
