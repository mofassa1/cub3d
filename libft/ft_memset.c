/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:51:46 by ousabbar          #+#    #+#             */
/*   Updated: 2023/10/31 09:51:55 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	k;
	unsigned char	*arr;

	i = 0;
	k = (unsigned char)c;
	arr = (unsigned char *)s;
	while (i < n)
	{
		arr[i] = k;
		i++;
	}
	return (arr);
}
