/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yasser <marvin@42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/10 11:04:41 by yasser        #+#    #+#                 */
/*   Updated: 2023/11/14 16:21:17 by yshalash      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

static int	digit_count(int n)
{
	int	number;
	int	count;

	number = n;
	count = 0;
	while (number != 0)
	{
		number /= 10;
		count++;
	}
	return (count);
}

int	ft_putnbr(int num)
{
	char	*str;
	int		number;
	int		i;


	if (num == 0)
		return (write(1, "0", 1));
	if (num == -2147483648)
		return (write(1, "-2147483648", 11));
	str = (char *)malloc(digit_count(num) * sizeof(char));
	if (str == NULL)
		return (-1);
	number = num;
	i = 0;
	if (number < 0)
	{
		write(1, "-", 1);
		number = -number;
	}
	while (number != 0)
	{
		str[i++] = (number % 10) + '0';
		number /= 10;
	}
	while (i-- > 0)
		write(1, &str[i], 1);
	free(str);
	if (num < 0)
		return (digit_count(num) + 1);
	else
		return (digit_count(num));
}
