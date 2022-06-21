/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewoo <jaewoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:10:15 by jaewoo            #+#    #+#             */
/*   Updated: 2021/12/09 16:27:13 by jaewoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	temp;

	i = 0;
	temp = ft_strlen(src);
	if (!dest || !src)
		return (0);
	while (i < temp && i + 1 < size)
	{
		dest[i] = src[i];
		i++;
	}
	if (0 < size)
		dest[i] = '\0';
	return (temp);
}
