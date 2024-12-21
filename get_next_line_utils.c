/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:44:03 by ehossain          #+#    #+#             */
/*   Updated: 2024/12/21 14:34:38 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	while (i < nmemb)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	static size_t	i;

	i = 0;
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
			return ((char *)&str[count]);
		count++;
	}
	if (str[count] == (char)i)
		return ((char *)&str[count]);
	return (NULL);
}

char	*ft_strdup(const char *str)
{
	static size_t	count;
	char			*buffer;

	count = 0;
	buffer = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
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
		len = ft_strlen(str) - start;
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	n;
	char	*dest;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	n = ft_strlen(s1) + ft_strlen(s2) + 1;
	dest = ft_calloc(sizeof(char) * n);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen(s2))
	{
		dest[j + i] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
