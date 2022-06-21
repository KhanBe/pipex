/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewoo <jaewoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 21:51:11 by jaewoo            #+#    #+#             */
/*   Updated: 2021/11/17 22:57:04 by jaewoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int alphabet)
{
	if ('A' <= alphabet && alphabet <= 'Z')
		return (1);
	else if ('a' <= alphabet && alphabet <= 'z')
		return (1);
	else
		return (0);
}
