/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:44:03 by ehossain          #+#    #+#             */
/*   Updated: 2024/12/18 17:38:34 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	static size_t	i;

	size_t = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *str, int i)
{
	static size_t	count;

	count = 0;
	while (str[count] != '\0')
	{
		if (str[count] == (char)i)
			return (str[count]);
		count++;
	}
	if (str[count] == (char)i)
		return (str[count]);
	return (NULL);
}

char	*ft_strdup(const char *str)
{
	static size_t	count;
	char			*buffer;

	count = 0;
	buffer = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	while (str[count] != '\0')
	{
		buffer[count] = str[count];
		count++;
	}
	buffer[count] = '\0';
	return (buffer);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	static size_t	count;
	char			*buffer;

	count = 0;
	if (!str)
		return (NULL);
	if (start >= ft_strlen(str))
		return (ft_strdup(""));
	if (len > ft_strlen(str) - start)
		len = ft_strlen - start;
	buffer = (char *)malloc(len + 1 * sizeof(char));
	while (str[count] && count < len)
	{
		buffer[count] = str[start];
		count++;
		start++;
	}
	buffer[count] = '\0';
	return (buffer);
}
