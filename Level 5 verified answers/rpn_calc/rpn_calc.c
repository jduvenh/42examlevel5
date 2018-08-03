/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 10:04:27 by exam              #+#    #+#             */
/*   Updated: 2018/07/19 11:35:18 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int 	ft_isdigit(char c)
{
	return ( c >= '0' && c <= '9');
}

int		ft_isspace(char c)
{
	return (c == ' ' || c == '\t');
}

int		isop(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

int		doop(int x, int y, char op)
{
	if (op == '+')
		return (x + y);
	if (op == '-')
		return (x - y);
	if (op == '*')
		return (x * y);
	if (op == '/')
		return (x / y);
	if (op == '%')
		return (x % y);
	return (0);
}

void	eval(char *str)
{
	int stack[4096] = {0};
	int top = 0;
	int i = 0;
	int temp = 0;

	while (str[i])
	{
		while(ft_isspace(str[i]))
			i++;
		if (ft_isdigit(str[i]) || (str[i] == '-' && ft_isdigit(str[i + 1])))
		{
			stack[++top] = atoi(str + i);
			if (str[i] == '-')
				i++;

			while(ft_isdigit(str[i]))
				i++;
		}
		if (isop(str[i]) && top > 1 && (ft_isspace(str[i + 1]) || str[i + 1] == '\0'))
		{
			if ((str[i] == '/' || str[i] == '%') && stack[top] == 0)
			{
				printf("Error\n");
				return ;
			}
			
			temp = doop(stack[top - 1], stack[top], str[i]);
			top--;
			stack[top] = temp;
			i++;
		}
		if (isop(str[i]) && str[i + 1] != ' ' && str[i + 1] != '\0')
		{
			printf("Error\n");
			return ;	
		}
		if (isop(str[i]) && top <= 1)
		{
			printf("Error\n");
			return;
		}
		if (!ft_isspace(str[i]) && !ft_isdigit(str[i]) && !isop(str[i]) && str[i]!= '\0')
		{
			printf("Error\n");
			return ;
		}
	}
	if (top == 1)
		printf("%d\n",stack[top]);
	else
		printf("Error\n");
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		eval(argv[1]);
	else
		printf("Error\n");
}
