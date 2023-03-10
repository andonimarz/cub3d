/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tools.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:07:19 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/16 11:55:24 by mruiz-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_TOOLS_H
# define STR_TOOLS_H

int		skip(char *str, int start);
int		skip_last_spaces(char *str);
int		find_space(char *str);
char	*check_last_line(char *str, char **my_map,
			t_state *state, t_file *file);
int		get_array_size(char **array);

#endif