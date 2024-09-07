/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:45:50 by ousabbar          #+#    #+#             */
/*   Updated: 2023/10/31 14:45:56 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_cast;
	unsigned char	*s;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	s = (unsigned char *)src;
	dest_cast = (unsigned char *)dest;
	i = 0;
	if (dest_cast <= s)
	{
		while (i < n)
		{
			dest_cast[i] = s[i];
			i++;
		}
	}
	else
		while (n--)
			dest_cast[n] = s[n];
	return (dest_cast);
}
