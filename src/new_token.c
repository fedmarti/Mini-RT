/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 22:12:52 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/26 19:11:34 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parsing.h"

void	next_char(char **file, int *i, int *j);
void	token_char_check(enum e_token_type *possible_types, t_pdata *data);
void	remove_type(enum e_token_type *arr, enum e_token_type type);

static int	tok_len(char **file, int i, int j)
{
	int	len;

	len = 0;
	while (file[i] && !ft_isspace(file[i][j]))
	{
		len++;
		next_char(file, &i, &j);
	}
	return (len);
}

enum e_token_type	number_type(float num)
{
	if (num >= 0 && num <= 1)
		return (NumberSingleRatio);
	if (num >= 0 && num <= 180)
		return (NumberSingleFov);
	if (num >= -1 && num <= 1)
		return (NumberSingleNormal);
	return (NumberSingle);
}

enum e_token_type	number_check(t_token *new, enum e_token_type generic_type)
{
	float				nums[3];
	enum e_token_type	types[sizeof(nums) / sizeof(*nums)];
	enum e_token_type	possible_types[5];
	int					i;

	// ft_bzero(&nums, sizeof(nums));
	parse_triplet((t_trip_interface){&nums[0], &nums[1], &nums[2]}, &(t_list){new, 0});
	types[0] = number_type(nums[0]);
	if (generic_type == NumberSingle && types[0] != NumberSingleNormal)
		return (types[0]);
	else if (generic_type == NumberSingle)
		return (NumberSingle);
	types[1] = number_type(nums[1]);
	types[2] = number_type(nums[2]);
	ft_memcpy(possible_types, (enum e_token_type[]){NumberSingleRatio, \
	NumberSingleNormal, NumberSingleFov, NumberSingle, eNull}, 20);
	i = 0;
	while (i < sizeof(nums) / sizeof(*nums))
	{
		if(nums[i] < 0)
		{
			remove_type(possible_types, NumberSingleRatio);
			remove_type(possible_types, NumberSingleFov);
		}
		if (nums[i] < -1 || nums[i] > 180)
			return (NumberTriplet);
		if (nums[i] > 1)
		{
			remove_type(possible_types, NumberSingleRatio);
			remove_type(possible_types, NumberSingleNormal);
		}
		i++;
	}
	return (possible_types[0]);
}

enum e_token_type	parse_type(t_token *new)
{
	enum e_token_type	possible_types[5];
	int					i;
	t_pdata				data;

	i = 0;
	ft_bzero(&data, sizeof(data));
	possible_types[0] = NumberSingle;
	possible_types[1] = NumberTriplet;
	possible_types[2] = ObjType;
	possible_types[3] = Garbage;
	possible_types[4] = eNull;
	while (new->str[i] && possible_types[0] != Garbage)
	{
		data.c = new->str[i];
		token_char_check(possible_types, &data);
		i++;
	}
	if (possible_types[0] == NumberSingle || possible_types[0] == NumberTriplet)
		return (number_check(new, possible_types[0]));
	return (possible_types[0]);
}

	//if all numeric NumberSingle
	//if three numbers NumberTriplet
	//if only characters type
	//else garbage

t_token	*new_token(char **file, int *i, int *j)
{
	int		len;
	t_token	*new;
	int		pos;

	len = tok_len(file, *i, *j);
	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->str = malloc(len + 1);
	if (!new->str)
	{
		free(new);
		return (NULL);
	}
	pos = 0;
	while (pos < len)
	{
		new->str[pos] = file[*i][*j];
		next_char(file, i, j);
		pos++;
	}
	new->str[pos] = '\0';
	new->type = parse_type(new);
	return (new);
}
