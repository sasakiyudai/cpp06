#include <iostream>
#include <limits>
#include "Convert.hpp"

int main(int argc, char *argv[])
{
	Convert converter;
	double d;
	
	if (argc == 2)
	{
		try
		{
			d = converter.convert(argv[1]);
			converter.dtoc(d);
			converter.dtoi(d);
			converter.dtof(d);
			converter.dtod(d);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			return (EXIT_FAILURE);
		}
	}
	else
	{
		std::cout << "Error: Invalid Input" << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
