/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reversepolish.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:57:57 by AleXwern          #+#    #+#             */
/*   Updated: 2024/11/25 21:27:31 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <vector>

const char *skipToNextSymbol(const char *str)
{
	while (*str != ' ' && *str != 0)
		str++;
	while (*str == ' ')
		str++;
	return str;
}

void		replaceValue(std::vector<int> &values, int result)
{
	values.pop_back();
	values.at(values.size()-1) = result;
}

std::string	reversePolishCalc(const char *str)
{
	std::vector<int>	numbers;
	int					result;

	while (*str)
	{
		while (*str == ' ')
			str++;
		if (*str >= '0' && *str <= '9')
			numbers.push_back(std::atoi(str));
		else
		{
			switch (*str)
			{
			case '+':
				result = numbers.at(numbers.size()-2) + numbers.at(numbers.size()-1);
				replaceValue(numbers, result);
				break;
			case '-':
				result = numbers.at(numbers.size()-2) - numbers.at(numbers.size()-1);
				replaceValue(numbers, result);
				break;
			case '*':
				result = numbers.at(numbers.size()-2) * numbers.at(numbers.size()-1);
				replaceValue(numbers, result);
				break;
			case '/':
				result = numbers.at(numbers.size()-2) / numbers.at(numbers.size()-1);
				replaceValue(numbers, result);
				break;
			}
		}
		str = skipToNextSymbol(str);
	}
	return std::to_string(numbers.at(0));
}

int		main(int argc, char **argv)
{
	(void)argc;
	if (argc < 2)
		return 1;
	std::cout << reversePolishCalc(argv[1]) << std::endl;
	return 0;
}
