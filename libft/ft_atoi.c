/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewoo <jaewoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 21:15:34 by jaewoo            #+#    #+#             */
/*   Updated: 2021/12/26 17:45:20 by jaewoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{	
		if (str[i++] == '-')
			sign *= -1;
	}
	while ('0' <= str[i] && str[i] <= '9')
		result = (result * 10) + (str[i++] - '0');
	return (result * sign);
}
