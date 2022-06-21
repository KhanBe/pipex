/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewoo <jaewoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:20:31 by jaewoo            #+#    #+#             */
/*   Updated: 2021/12/26 19:11:47 by jaewoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	right;
	size_t	left;
	char	*result;

	if (s1 == NULL || set == NULL)
		return (0);
	left = 0;
	right = ft_strlen(s1);
	while (s1[left] && ft_strchr(set, s1[left]))
		left++;
	while (s1[right - 1] && ft_strchr(set, s1[right - 1]))
		right--;
	if (left > right)
		return (ft_strdup(""));
	result = ft_substr(s1, left, right - left);
	return (result);
}
