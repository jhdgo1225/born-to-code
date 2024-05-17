#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP
# include <iostream>
# include <cstdlib>
# include <cmath>

class ScalarConverter
{
public:
	static void convert(std::string rawData);
private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter& rhs);
	ScalarConverter& operator=(const ScalarConverter& rhs);
};

#endif
