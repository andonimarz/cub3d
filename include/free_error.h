/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:57:03 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/13 10:05:17 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_ERROR_H
# define FREE_ERROR_H

# include"cub3d.h"

int		free_txt(t_txt *txt);
int		free_color(t_color *color);
void	free_array(char **array);
int		exit_with_error(t_state *state, char *str);
int     exit_without_error(t_state *state);
void	file_error(char *av);
int		txt_color_errors(t_state *state, t_file *file, char **my_map);

#endif