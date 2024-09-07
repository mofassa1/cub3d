/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:01:49 by ousabbar          #+#    #+#             */
/*   Updated: 2023/11/04 10:01:52 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	if (!(*needle))
		return ((char *)haystack);
	if (!haystack && !needle)
		return (NULL);
	i = 0;
	j = 0;
	while (haystack[i])
	{
		while (haystack[i] == needle[j] && i < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i - j]);
			j++;
			i++;
		}
		i = i - j + 1;
		j = 0;
	}
	return (NULL);
}
