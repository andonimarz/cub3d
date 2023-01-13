/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:03:04 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/11 11:09:26 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# include"cub3d.h"

int		parse_file(char *av, t_state *state);
int		file_size(int fd);
int		txt_file_check(char *route);
int		ext_checker(char *str, char *ext);

#endif