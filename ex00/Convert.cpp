#include "Convert.hpp"
#include <iostream>
#include <cmath>
#include <limits>

Convert::Convert()
{

}

Convert::Convert(Convert const &other)
{
	(void)other;
}

Convert::~Convert()
{

}

Convert &Convert::operator=(Convert const &other)
{
	(void)other;
	return (*this);
}

double Convert::convert(std::string const &literal)
{
	double ret;

	try
	{
		if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
			ret = static_cast<double>(literal[1]);
		else
			ret = std::stod(literal);
	}
	catch(const std::exception &e)
	{
		throw Convert::InvalidInputException();
	}
	return (ret);
}

const char* Convert::InvalidInputException::what() const throw()
{
	return "Error: Invalid Input";
}

void Convert::dtoc(double d)
{
	std::cout << "char: ";

	if (d < 0 || 127 < d || std::isnan(d))
		std::cout << "impossible";
	else if (d < 32 || 126 < d)
		std::cout << " Non displayable";
	else
		std::cout << "'" << static_cast<char>(d) << "'";
	std::cout << std::endl;
}

void Convert::dtoi(double d)
{
	std::cout << "int: ";

	if (std::isnan(d) || d < std::numeric_limits<int>::min() || std::numeric_limits<int>::max() < d)
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(d);
	std::cout << std::endl;
}

void Convert::dtof(double d)
{
	std::cout << "float: ";
	std::cout << static_cast<float>(d);
	if (d == std::floor(d))
		std::cout << ".0f";
	else
		std::cout << "f";
	std::cout << std::endl;
}

void Convert::dtod(double d)
{
	std::cout << "double: ";
	std::cout << static_cast<double>(d);
	if (d == std::floor(d))
		std::cout << ".0";
	else
		std::cout << "";
	std::cout << std::endl;
}
