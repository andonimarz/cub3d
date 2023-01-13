/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tools.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:07:19 by mruiz-sa          #+#    #+#             */
/*   Updated: 2023/01/13 12:23:42 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_TOOLS_H
# define STR_TOOLS_H

int		skip(char *str, int start);
int		find_space(char *str);
char	*check_last_line(char *str, char **my_map,
			t_state *state, t_file *file);

#endif