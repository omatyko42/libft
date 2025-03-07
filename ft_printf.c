/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatyko <omatyko@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:50:07 by omatyko           #+#    #+#             */
/*   Updated: 2025/03/04 13:06:56 by omatyko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	case_next_symbol(va_list args, const char *str, int *count)
{
	int	res;

	if (*str == 'c')
		res = prn_char(va_arg(args, int));
	else if (*str == 's')
		res = prn_str(va_arg(args, char *));
	else if (*str == 'p')
		res = prn_ptr(va_arg(args, uintptr_t), "0x");
	else if (*str == 'd' || *str == 'i')
		res = prn_nbr(va_arg(args, int));
	else if (*str == 'x' || *str == 'X')
		res = prn_u_hex(va_arg(args, unsigned int), 16, *str);
	else if (*str == 'u')
		res = prn_u_hex(va_arg(args, unsigned int), 10, '0');
	else if (*str == '%')
		res = prn_char('%');
	else if (is_alpha(str) && !is_prefix(str))
		res = print_non_def_prefix(str);
	else
		res = -1;
	if (res == -1)
		return (res);
	*count += res;
	return (*count);
}

int	check_wrong_prefix(const char *str)
{
	if (*str == '%' && *(str + 1) == '\0')
		return (-1);
	else
		return (0);
}

void	print_char_with_errcheck(const char *str, int *count)
{
	int	res;

	res = prn_char(*str);
	if (res == -1)
		*count = -1;
	*count += res;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, str);
	count = check_wrong_prefix(str);
	while (*str && count != -1)
	{
		if (*str == '%')
		{
			if (case_next_symbol(args, str + 1, &count) == -1)
			{
				va_end(args);
				return (-1);
			}
			str++;
		}
		else
			print_char_with_errcheck(str, &count);
		str++;
	}
	va_end(args);
	return (count);
}
