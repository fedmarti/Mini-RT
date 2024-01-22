/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:29:41 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/22 21:43:10 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include "rt_parsing.h"

static int	is_rt_file(char *filename)
{
	char *find;

	find = ft_strnstr(filename, ".rt", INT_MAX);
	while (find && find[3])
	{
		find = ft_strnstr(find, ".rt", INT_MAX);
	}
	return (find != NULL);
}

t_scene	*parse_rt(char *filename)
{
	char	**file;
	t_list	*tokens;

	if (!is_rt_file(filename))
	{
		write (2, "This isn't a .rt file!\n", 23);
		return (NULL);
	}
	file = ft_read_file(filename);
	if (!file)
		return (NULL);
	tokens = tokenize_file(file);
}