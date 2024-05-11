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
	static bool	checkInfAndNan(std::string& val, const size_t& sz);
	static bool	checkNumber(const std::string& val, const size_t& sz, bool& fracPart);
	static void	cvtToChar(const double& info);
	static void	cvtToInt(const double& info);
	static void	cvtToFloat(const double& info, const size_t& sz, const bool& fracPart);
	static void	cvtToDouble(const double& info, const size_t& sz, const bool& fracPart);
};

#endif
