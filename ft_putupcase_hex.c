/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putupcase_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:11:08 by yasser            #+#    #+#             */
/*   Updated: 2023/11/13 20:22:12 by yasser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int	digit_count(int n)
{
	int	number;
	int	count;

	number = n;
	count = 0;
		if (n == 0)
		count++;
	while (number != 0)
	{
		number /= 10;
		count++;
	}
	return (count);
}

int	ft_put_upcase_hex(unsigned int num)
{
	char			*str;
	char			*base;
	unsigned int	number;
	unsigned int				i;
	unsigned int				j;

	if (num == 0)
		return (write(1, "0", 1));
	str = (char *)malloc(digit_count(num) * sizeof(char));
	if (str == NULL)
		return (-1);
	base = "0123456789ABCDEF";
	number = num;
	i = 0;
	while (number != 0)
	{
		str[i++] = base[number % 16];
		number /= 16;
	}
	j = i;
	while (i-- > 0)
		write(1, &str[i], 1);
	free(str);
	return (j);
}
