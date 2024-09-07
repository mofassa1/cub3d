/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:46:20 by afadouac          #+#    #+#             */
/*   Updated: 2023/11/29 21:47:41 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	new_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		new_str[i++] = s2[j++];
	free(s1);
	new_str[i] = '\0';
	if (!new_str[0])
		return (free(new_str), NULL);
	return (new_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*the_return;
	size_t	i;

	if (!s)
		return (NULL);
	i = ft_strlen((char *)s);
	if (i <= start)
		len = 0;
	if (i - start < len)
		len = i - start;
	the_return = (char *)malloc(sizeof(char) * (len + 1));
	if (!the_return)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		the_return[i] = s[start + i];
		i++;
	}
	the_return[i] = '\0';
	return (the_return);
}
