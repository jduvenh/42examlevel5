/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_pal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 11:51:42 by cking             #+#    #+#             */
/*   Updated: 2018/07/26 14:25:41 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int len = 0;
	while (str[len])
		len++;
	return len;
}

int		is_pal(char *str, int i, int j)
{
	while ((j - i) > 0)
		if (str[i++] != str[j--])
			return 0;
	return 1;
}

int 	main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *str = argv[1];
		int len = ft_strlen(str);
		
		if (is_pal(str,0,(len - 1)))
		{
			write(1, str, len);
		}
		else
		{
			int s = 0;
			int e = 0;

			for (int i = 0; (i < len); i++)
			{
				for (int j = 0; j < len; j++)
				{
					if (is_pal(str, i, j))
					{
						if ((j - i) > (e - s))
						{
							s = i;
							e = j;
						}
					}
				}
			}
			write(1, (str + s), (e - s + 1));
		}
	}
	write (1, "\n", 1);
}
