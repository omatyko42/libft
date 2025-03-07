/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatyko <omatyko@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 00:58:30 by omatyko           #+#    #+#             */
/*   Updated: 2025/03/06 15:31:52 by omatyko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		minus;
	long	res;

	i = 0;
	minus = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if ((minus * res) != (int)(minus * res))
		return (-1);
	return ((int)(minus * res));
}

int	ft_atoi_base(const char *str, const char *base)
{
	int	neg;
	int	result;
	int	nbase;	

	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	neg = 1;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	nbase = ft_strlen(base);
	result = 0;
	while (str && *str && ft_strchr(base, *str))
	{
		result = result * nbase + ft_strchr(base, *str) - base;
		str++;
	}
	return (neg * result);
}
