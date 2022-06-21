/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewoo <jaewoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:32:32 by jaewoo            #+#    #+#             */
/*   Updated: 2021/11/23 11:49:11 by jaewoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*temp;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	temp = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!temp)
		return (NULL);
	ft_memcpy(temp, s1, len1);
	ft_memcpy(temp + len1, s2, len2);
	temp[len1 + len2] = '\0';
	return (temp);
}
