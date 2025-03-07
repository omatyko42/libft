/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatyko <omatyko@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:50:15 by omatyko           #+#    #+#             */
/*   Updated: 2025/03/04 13:07:02 by omatyko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_alpha(const char *str)
{
	return ((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z'));
}

int	is_prefix(const char *str)
{
	const char	*prefix = "cspdiuxX%";

	while (*prefix)
	{
		if (*prefix == *str)
		{
			return (1);
		}
		prefix++;
	}
	return (0);
}

int	print_non_def_prefix(const char *str)
{
	int	res;

	res = prn_char('%');
	if (res == -1)
		return (-1);
	res = prn_char(*str);
	if (res == -1)
		return (-1);
	else
		return (2);
}
