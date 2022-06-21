/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewoo <jaewoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:19:57 by jaewoo            #+#    #+#             */
/*   Updated: 2021/12/26 18:14:41 by jaewoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*array;
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	array = (char *)malloc(sizeof(char) * (len + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		array[i] = src[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}
