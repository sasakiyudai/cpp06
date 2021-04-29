#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <string>

class Convert
{
	public:
		Convert();
		Convert(Convert const &other);
		virtual ~Convert();
		Convert &operator=(Convert const &other);

		double convert(std::string const &literal);
		class InvalidInputException: public std::exception
		{
			public:
				const char* what() const throw();
		};
		void dtoc(double);
		void dtoi(double);
		void dtof(double);
		void dtod(double);
};

#endif
