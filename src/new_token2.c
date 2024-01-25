/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_token2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 20:42:20 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/25 22:17:52 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parsing.h"

static inline void	remove_type(enum e_token_type *arr, enum e_token_type type)
{
	int	i;
	int	j;

	if (type == E_NULL)
		return ;
	i = 0;
	while (arr[i] != E_NULL)
	{
		if (arr[i] == type)
		{
			j = i + 1;
			arr[i] = arr[j];
			while (arr[j] != E_NULL)
			{
				arr[j] = arr[j + 1];
				j++;
			}
		}
		i++;
	}
}

static void	comma_logic(enum e_token_type *possible_types, t_pdata *data)
{
	data->comma_count++;
	if (data->comma_count > 2)
	{
		possible_types[0] = Garbage;
		return ;
	}
	if (possible_types[0] == NumberSingle)
		remove_type(possible_types, NumberSingle);
	data->point_count = 0;
	data->sign_count = 0;
}

static void	sign_logic(enum e_token_type *possible_types, t_pdata *data)
{
	data->sign_count++;
	if (data->sign_count > 1)
	{
		possible_types[0] = Garbage;
		return ;
	}
	remove_type(possible_types, ObjType);
}

void	token_char_check(enum e_token_type *possible_types, t_pdata *data)
{
	if (ft_isalpha(data->c))
	{
		remove_type(possible_types, NumberSingle);
		remove_type(possible_types, NumberTriplet);
	}
	else if (ft_isdigit(data->c))
	{
		remove_type(possible_types, ObjType);
		data->sign_count = 1;
	}
	else if (data->c == ',')
		comma_logic(possible_types, data);
	else if (data->c == '.')
	{
		remove_type(possible_types, ObjType);
		data->point_count++;
		if (data->point_count > 1)
			possible_types[0] = Garbage;
	}
	else if (data->c == '-' || data->c == '+')
		sign_logic(possible_types, data);
	else
		possible_types[0] = Garbage;
}
