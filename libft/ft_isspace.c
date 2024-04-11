/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <dsheng1993@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:32:39 by fedmarti          #+#    #+#             */
/*   Updated: 2024/04/11 17:13:43 by shhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(int c)
{
	return ((c == ' ') \
	|| (c == '\t') || (c == '\n') || (c == '\v') || (c == '\f') || (c == '\r'));
}
