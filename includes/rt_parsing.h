/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:43:52 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/26 23:22:28 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PARSING_H
# define RT_PARSING_H

# include "libft.h"
# include "objects.h"
# include "symbols.h"
# define TTM_SIZE 6

//the enums vals are chosen in such a way that any one type is greater
//than any more specific versions of the same type
//example: NumberSingleRatio is also a nsFov, nsNormal and NumberSingle 
enum	e_token_type
{
	NumberSingleRatio,
	NumberSingleNormal,
	NumberSingleFov,
	NumberSingle,
	NumberTripletRatio,
	NumberTripletNormal,
	NumberTripletColor,
	NumberTriplet,
	ObjType,
	Garbage,
	eNull
};
//E_NULL needs to be capitalized because of norminette

typedef struct s_triplet_parsing_interface
{
	float	*x;
	float	*y;
	float	*z;
}	t_trip_interface;

typedef struct s_type_parsing_data
{
	char				c;
	int					point_count;
	int					comma_count;
	int					sign_count;
}	t_pdata;

typedef struct s_token
{
	char				*str;
	enum e_token_type	type;
}	t_token;

t_list			*tokenize_file(char **file);
t_token			*new_token(char **file, int *i, int *j);
void			free_token(void *tok);
t_light			light_init(t_list *tokens);
t_shape			shape_init(t_list *tokens);
t_camera		camera_init(t_list *tokens);
t_lighting		ambient_init(t_list *tokens);
unsigned int	parse_color(t_list *token);
void			parse_triplet(t_trip_interface interface, t_list *token);
t_scene			*parse_rt(char *filename);

#endif