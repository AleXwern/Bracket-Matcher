/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:05:43 by AleXwern          #+#    #+#             */
/*   Updated: 2024/11/25 17:53:13 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <vector>

std::string	bracketMatcher(const char *src)
{
	std::vector<char>	brackets = {0};
	int					bracketCount = 0;

	while (*src && bracketCount != -1)
	{
		switch (*src)
		{
		case '(':
		case '[':
			brackets.push_back(*src);
			break;
		case ']':
			if (brackets.back() != '[')
				bracketCount = -1;
			else
			{
				bracketCount++;
				brackets.pop_back();
			}
			break;
		case ')':
			if (brackets.back() != '(')
				bracketCount = -1;
			else
			{
				bracketCount++;
				brackets.pop_back();
			}
			break;
		}
		src++;
	}
	if (bracketCount > 0 && brackets.size() == 1)
		return "1 " + std::to_string(bracketCount);
	else
		return "0";
}

int		main(int argc, char **argv)
{
	(void)argc;
	if (argc < 2)
		std::cout << bracketMatcher("") << std::endl;
	else
		std::cout << bracketMatcher(argv[1]) << std::endl;
	return 0;
}
