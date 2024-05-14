#include "ScalarConverter.hpp"
#include <limits>

bool	ScalarConverter::checkInfAndNan(std::string& val, const size_t& sz)
{
	if (sz < 3 || sz > 5)
		return (false);
	size_t idx = 0;
	while (idx < sz)
	{
		val[idx] = tolower(val[idx]);
		idx++;
	}
	if (!val.compare("inf") || !val.compare("+inf") || !val.compare("-inf")
		|| !val.compare("inff") || !val.compare("+inff") || !val.compare("-inff")
		|| !val.compare("nan") || !val.compare("nanf"))
		return (true);
	return (false);
}

bool	ScalarConverter::checkNumber(const std::string& val, const size_t& sz, bool& fracPart)
{
	size_t	idx = 0;
	bool	isNum = false;
	bool	isDecimalPoint = false;

	while (val[idx] == '+' || val[idx] == '-')
		idx++;
	while (idx < sz)
	{
		if (idx + 1 == sz && (val[idx] == 'f' || val[idx] == 'F'))
		{
			idx++;
			continue;
		}
		if (val[idx] < '0' || val[idx] > '9')
		{
			if (val[idx] == '.' && isNum && !isDecimalPoint)
			{
				isNum = false;
				isDecimalPoint = true;
			}
			else
				return (false);
		}
		if (val[idx] >= '0' && val[idx] <= '9')
		{
			if (isDecimalPoint && (val[idx] >= '1' && val[idx] <= '9'))
				fracPart = true;
			isNum = true;
		}
		idx++;
	}
	return (true);
}

void	ScalarConverter::cvtToChar(const double& info)
{
	int	checkChar = static_cast<int>(info);
	std::cout << "char: ";
	if (info == std::numeric_limits<double>::infinity()
		|| info != info)
	{
		std::cout << "impossible" << '\n';
		return ;
	}
	if (checkChar >= 32 && checkChar <= 126)
		std::cout << '\'' << static_cast<char>(checkChar) << '\'' << '\n';
	else if ((checkChar >= 0 && checkChar < 32) || checkChar == 127)
		std::cout << "Non displayable" << '\n';
	else
		std::cout << "impossible" << '\n';
}

void	ScalarConverter::cvtToInt(const double& info)
{
	long long	checkInt = static_cast<long long>(info);
	std::cout << "int: ";
	if (info == std::numeric_limits<double>::infinity()
		|| info != info)
	{
		std::cout << "impossible" << '\n';
		return ;
	}
	if (checkInt >= std::numeric_limits<int>::min() && checkInt <= std::numeric_limits<int>::max())
		std::cout << checkInt << '\n';
	else
		std::cout << "impossible" << '\n';
}

void	ScalarConverter::cvtToFloat(const double& info, const size_t& sz, const bool& fracPart)
{
	float	checkFloat = static_cast<float>(info);
	std::cout << "float: ";
	std::cout << checkFloat;
	if (sz == 1 || (checkFloat == checkFloat && checkFloat != std::numeric_limits<float>::infinity() && checkFloat != std::numeric_limits<float>::infinity() * (-1) && !fracPart))
		std::cout << ".0";
	std::cout << "f" << '\n';
}

void	ScalarConverter::cvtToDouble(const double& info, const size_t& sz, const bool& fracPart)
{
	std::cout << "double: ";
	std::cout << info;
	if (sz == 1 || (info == info && info != std::numeric_limits<double>::infinity() && info != std::numeric_limits<float>::infinity() * (-1) && !fracPart))
		std::cout << ".0";
	std::cout << '\n';
}

void	ScalarConverter::convert(std::string rawData)
{
	size_t	strSize = rawData.size();
	bool fractionalPart = false;
	double	numInfo;
	if (strSize == 1 && ((rawData[0] >= 32 && rawData[0] < '0') || (rawData[0] > '9' && rawData[0] <= 126)))
		numInfo = static_cast<double>(rawData[0]);
	else if (strSize == 3 && (rawData[0] == '\'' && rawData[2] == '\'' && (rawData[1] >= 32 && rawData[1] <= 126)))
		numInfo = static_cast<double>(rawData[1]);
	else if (checkInfAndNan(rawData, strSize) || checkNumber(rawData, strSize, fractionalPart))
		numInfo = atof(rawData.c_str());
	else
	{
		std::cout << "char: impossible" << '\n';
		std::cout << "int: impossible" << '\n';
		std::cout << "float: impossible" << '\n';
		std::cout << "double: impossible" << '\n';
		return ;
	}
	cvtToChar(numInfo);
	cvtToInt(numInfo);
	cvtToFloat(numInfo, strSize, fractionalPart);
	cvtToDouble(numInfo, strSize, fractionalPart);
}
