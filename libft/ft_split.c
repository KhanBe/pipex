/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewoo <jaewoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 01:30:46 by jaewoo            #+#    #+#             */
/*   Updated: 2021/12/27 15:49:35 by jaewoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	freestr(char **str, size_t index)
{
	while (index--)
	{
		free(str[index]);
		str[index] = NULL;
	}
	free(str);
	str = NULL;
}

static	size_t	get_size(const char *s, char c)
{
	size_t	i;
	size_t	result;

	i = 0;
	result = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			result++;
		}
	}
	return (result);
}

size_t	get_end(const char *s, char c, size_t end)
{
	while (s[end] != c && s[end])
		end++;
	return (end);
}

static char	**splitcpy(char **str, const char *s, char c, size_t split_size)
{
	size_t	index;
	size_t	start;
	size_t	end;

	index = 0;
	end = 0;
	while (s[end] == c && s[end])
		end++;
	while (index < split_size)
	{
		start = end;
		end = get_end(s, c, end);
		str[index] = malloc(sizeof(char) * (end - start + 1));
		if (!str[index])
		{
			freestr(str, index);
			return (NULL);
		}
		ft_strlcpy(str[index], s + start, end - start + 1);
		while (s[end] == c)
			end++;
		index++;
	}
	str[split_size] = NULL;
	return (str);
}

char	**ft_split(const char *s, char c)
{
	char	**str;
	size_t	split_size;

	if (!s)
		return (NULL);
	split_size = get_size(s, c);
	str = malloc(sizeof(char *) * (split_size + 1));
	if (!str)
		return (NULL);
	if (!splitcpy(str, s, c, split_size))
		return (NULL);
	return (str);
}
