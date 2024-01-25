/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:45:36 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/25 22:12:14 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_atof(char *str)
{
	float	num;
	int		sign;
	int		pow;
	int		i;

	num = 0;
	while (ft_isspace(*str))
		str++;
	sign = 1 - (2 * (*str == '-'));
	i = (*str == '+' || *str == '-');
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + (str[i] - '0') * sign;
		i++;
	}
	if (str[i++] != '.')
		return (num);
	pow = 10;
	while (ft_isdigit(str[i]))
	{
		num += (float)(str[i] - '0') / pow * sign;
		i++;
		pow *= 10;
	}
	return (num);
}
