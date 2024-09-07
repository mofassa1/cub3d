/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:21:19 by ousabbar          #+#    #+#             */
/*   Updated: 2023/10/31 10:21:30 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*s;
	size_t			i;

	s = (unsigned char *)src;
	dst = (unsigned char *)dest;
	i = 0;
	if (!s && !dst)
		return (NULL);
	if (s == dst)
		return (dst);
	while (i < n)
	{
		dst[i] = s[i];
		i++;
	}
	return (dst);
}
