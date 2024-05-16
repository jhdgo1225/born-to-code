#include "ScalarConverter.hpp"
#include <sstream>
#include <limits>

bool	checkInfAndNan(const std::string& val, const size_t& sz)
{
	if (sz < 3 || sz > 5)
		return (false);
	size_t idx = 0;
	std::string tmp = val;
	while (idx < sz)
	{
		tmp[idx] = tolower(tmp[idx]);
		idx++;
	}
	if (!tmp.compare("inf") || !tmp.compare("+inf") || !tmp.compare("-inf")
		|| !tmp.compare("inff") || !tmp.compare("+inff") || !tmp.compare("-inff")
		|| !tmp.compare("nan") || !tmp.compare("nanf"))
		return (true);
	return (false);
}

bool	checkNumber(const std::string& val, const size_t& sz, bool *point)
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
			isNum = true;
		idx++;
	}
	if (point)
		*point = isDecimalPoint;
	return (true);
}

char	cvtToChar(const std::string& rawData, size_t& strSize)
{
	char charInfo = -1;
	if (strSize == 1 && ((rawData[0] >= 32 && rawData[0] < '0') || (rawData[0] > '9' && rawData[0] <= 126)))
		charInfo = static_cast<char>(rawData[0]);
	else if (strSize == 3
		&& (((rawData[0] == '\'' && rawData[2] == '\'') || (rawData[0] == '"' || rawData[2] == '"'))
			&& (rawData[1] >= 32 && rawData[1] <= 126)))
		charInfo = static_cast<char>(rawData[1]);
	else if (checkNumber(rawData, strSize, NULL))
	{
		double num = atof(rawData.c_str());
		if (num >= 0 && num <= 127)
			charInfo = static_cast<char>(num);
	}
	std::cout << "char: ";
	if (charInfo >= 32 && charInfo <= 126)
		std::cout << '\'' << static_cast<char>(charInfo) << '\'' << '\n';
	else if ((charInfo >= 0 && charInfo < 32) || charInfo == 127)
		std::cout << "Non displayable" << '\n';
	else
		std::cout << "impossible" << '\n';
	return (charInfo);
}

void	cvtToInt(const std::string& rawData, size_t& strSize, char isRealChar)
{
	std::cout << "int: ";
	if (isRealChar != -1)
		std::cout << static_cast<int>(isRealChar) << '\n';
	else if (checkInfAndNan(rawData, strSize) || checkNumber(rawData, strSize, NULL))
	{
		double num = atof(rawData.c_str());
		if (num >= std::numeric_limits<int>::min()
			&& num <= std::numeric_limits<int>::max())
			std::cout << static_cast<int>(num) << '\n';
		else
			std::cout << "impossible" << '\n';
	}
	else
		std::cout << "impossible" << '\n';
}

void	cvtToFloat(const std::string& rawData, size_t& strSize, char isRealChar)
{
	float checkFloat = 0.0f;
	bool 	fracPart = false;
	std::cout << "float: ";
	if (checkInfAndNan(rawData, strSize))
		checkFloat = static_cast<float>(atof(rawData.c_str()));
	else if (checkNumber(rawData, strSize, &fracPart))
		checkFloat = static_cast<float>(atof(rawData.c_str()));
	else if (isRealChar != -1)
		checkFloat = static_cast<double>(isRealChar);
	else
	{
		std::cout << "impossible" << '\n';
		return ;
	}
	std::cout << checkFloat;
	if (checkFloat == checkFloat && checkFloat != std::numeric_limits<float>::infinity() && checkFloat != std::numeric_limits<float>::infinity() * (-1) && !fracPart)
		std::cout << ".0";
	std::cout << "f" << '\n';
}

void	cvtToDouble(const std::string& rawData, size_t& strSize, char isRealChar)
{
	double	checkDouble = 0;
	bool 	fracPart = false;
	std::cout << "double: ";
	if (checkInfAndNan(rawData, strSize))
		checkDouble = static_cast<double>(atof(rawData.c_str()));
	else if (checkNumber(rawData, strSize, &fracPart))
		checkDouble = static_cast<double>(atof(rawData.c_str()));
	else if (isRealChar != -1)
		checkDouble = static_cast<double>(isRealChar);
	else
	{
		std::cout << "impossible" << '\n';
		return ;
	}
	std::cout << checkDouble;
	if (checkDouble == checkDouble && checkDouble != std::numeric_limits<double>::infinity() && checkDouble != std::numeric_limits<double>::infinity() * (-1) && !fracPart)
		std::cout << ".0";
	std::cout << '\n';
}

void	ScalarConverter::convert(std::string rawData)
{
	size_t	strSize = rawData.size();
	char	isRealChar = cvtToChar(rawData, strSize);
	cvtToInt(rawData, strSize, isRealChar);
	cvtToFloat(rawData, strSize, isRealChar);
	cvtToDouble(rawData, strSize, isRealChar);
}
