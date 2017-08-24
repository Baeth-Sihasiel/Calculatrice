#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(int select, char *input)
{
	int		lng;

	while (input[select] != '\0')
	{
		lng = lng + 1;
	}
	return (lng);
}

int		calcul(int op1, char operateur, int op2)
{
	if (operateur == '*')
		return (op1 * op2);
	if (operateur == '%')
		return (op1 % op2);
	if (operateur == '-')
		return (op1 - op2);
	if (operateur == '+')
		return (op1 + op2);
	if (operateur == '/')
		return (op1 / op2);
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_display(char *str)
{
	int		select;

	select = 0;
	while (str[select])
	ft_putchar(str[select]);
}

char	*ft_strcpy(char *input, int select)
{
	char	*newput;
	int		filler;

	filler = 0;
	while (input[select] != '\0')
	{
		newput[filler] = input[select];
		select++;
		filler++;
	}
	newput[filler] = '\0';
	return (newput);
}

int		calculsimple(char *input, int select)
{
	int		op1;
	int		op2;
	char	operateur;
	int		resultat;
	char	*newput;
	int		position;
	int		levier;
	int		levier2;

	levier = 1;
	levier2 = 1;
	op1 = 0;
	op2 = 0;
		while (input[select] < 47 || input[select] > 58)
		{
			if (input[select] == '-')
				levier = -1;
			select++;
		}
		while (input[select] > 47 && input[select] < 58)
		{
			op1 = op1 * 10 + (input[select] - '0');
			select++;
		}
		op1 = op1 * levier;
		while (input[select] != '\0')
		{
			while (input[select] != '%' || input[select] != '*'
			|| input[select] != '-' || input[select] != '+'
			|| input[select] != '/')
				select++;
			operateur = input[select];
			while (input[select] < 47 || input[select] > 58)
			{
				if (input[select] == '-')
					levier2 = -1;
					select++;
			}
			while (input[select] > 47 && input[select] < 58)
			{
				op2 = op2 * 10 + (input[select] - '0');
				select++;
			}
			op2 = op2 * levier;
			position = select;
			resultat = calcul(op1, operateur, op2);
			op1 = resultat;
			newput = malloc(sizeof(char) * ft_strlen(position, input));
			newput = ft_strcpy(input, select);
		}
		ft_display(newput);
		return (0);
}

int		main(int argc, char **argv)
{
	char	*input;
	int		parentheses;
	int		select;

	select = 0;
	parentheses = 0;
	if (argc < 2)
		return (0);
	*input = *argv[1];
	while (input[select])
	{
		if (input[select] == '(')
			parentheses++;
		select++;
	}
	select = 0;
	if (parentheses < 1)
		calculsimple(input, select);
	else
		return (0);
	return (0);
	}
