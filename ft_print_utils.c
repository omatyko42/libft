/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatyko <omatyko@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:50:37 by omatyko           #+#    #+#             */
/*   Updated: 2025/03/06 15:14:10 by omatyko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	prn_u_hex(unsigned int num, unsigned int base, char upper)
{
	char	*nmb;
	int		c;
	int		cr;

	c = 0;
	cr = 0;
	nmb = "0123456789abcdef";
	if (num >= base)
		cr = prn_u_hex(num / base, base, upper);
	if (cr == -1)
		return (-1);
	if ((nmb[num % base]) >= 'a' && (nmb[num % base]) <= 'f' && upper == 'X')
		c = prn_char(nmb[num % base] - 32);
	else
		c = prn_char(nmb[num % base]);
	if (c == -1)
		return (-1);
	return (c + cr);
}

int	prn_str(const char *str)
{
	int	c;
	int	res;

	c = 0;
	res = 0;
	if (str == NULL)
		return (prn_str("(null)"));
	while (*str)
	{
		res = prn_char(*str);
		if (res == -1)
			return (-1);
		c += res;
		str++;
	}
	return (c);
}

int	prn_ptr(uintptr_t num, char *prefix)
{
	char	*nmb;
	int		c;
	int		cr;

	nmb = "0123456789abcdef";
	c = 0;
	cr = 0;
	if (!num)
		return (prn_str("(nil)"));
	if (*prefix)
		c = prn_str(prefix);
	if (c == -1)
		return (-1);
	if (num >= 16)
		cr = prn_ptr(num / 16, "");
	if (cr == -1)
		return (-1);
	if (prn_char(nmb[num % 16]) == -1)
		return (-1);
	return (c + cr + 1);
}

int	prn_nbr(int num)
{
	int	c;
	int	cr;

	c = 0;
	cr = 0;
	if (num < 0)
	{
		if (num == -2147483648)
			return (prn_str("-2147483648"));
		c = prn_char('-');
		if (c == -1)
			return (-1);
		num = -num;
	}
	if (num >= 10)
		cr = prn_nbr(num / 10);
	if (cr == -1)
		return (-1);
	if (prn_char((num % 10) + '0') == -1)
		return (-1);
	return (c + cr + 1);
}

int	prn_char(char c)
{
	return (write(1, &c, 1));
}
