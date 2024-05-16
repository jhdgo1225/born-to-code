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
bool	checkInfAndNan(std::string& val, const size_t& sz);
bool	checkNumber(const std::string& val, const size_t& sz, bool *point);
char	cvtToChar(const std::string& rawData, size_t& strSize);
void	cvtToInt(const std::string& rawData, size_t& strSize, char isRealChar);
void	cvtToFloat(const std::string& rawData, size_t& strSize, char isRealChar);
void	cvtToDouble(const std::string& rawData, size_t& strSize, char isRealChar);

#endif
