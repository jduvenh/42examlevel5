
#include <unistd.h>

int		is_bracket(char c)
{
	if (c == '(' || c == '[' || c == '{')
		return 1;
	if (c == ')' || c == ']' || c == '}')
		return 2;
	return 0;
}

int		match_brackets(char a, char b)
{
	return ((b-a) <= 2 && (b-a) >= -2);
}

int		check_brackets(char *str)
{
	int stack[4096];
	int top = 0;
	int i = 0;

	while (str[i])
	{
		if (is_bracket(str[i]) == 1)
			stack[++top] = str[i];
		if (is_bracket(str[i]) == 2)
			if(!match_brackets(stack[top--],str[i]))
				return 0;
		i++;
	}
	return (!top);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		write(1, "\n", 1);
	else
	{
		char *str;
		int i = 1;
		while (i < argc)
		{
			str = argv[i];
			if (check_brackets(str))
				write(1, "OK\n", 3);
			else
				write(1, "Error\n", 6);
			i++;
		}
	}
}
