/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:27:38 by amarzana          #+#    #+#             */
/*   Updated: 2023/01/18 10:29:37 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKERS_H
# define CHECKERS_H

# include "cub3d.h"

//checkers.c
int				arg_checker(int ac, char **av);

//check_coherence.c
int				parse_map(t_state *state, t_file *file, char **my_map);
void			check_coherence(t_state *state, char **my_map);

//check_coherence2.c
void			check_map_limit_rev(char **my_map, t_coher *c, int i);
void			check_map_limit(char **my_map, t_coher *c);

#endif
