#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <map>

void	testOpenFile(const std::string filename)
{
	std::ifstream tester(filename.c_str());
	if (!tester.is_open())
	{
		std::cerr << "Error: \"" << filename << "\" open error" << '\n';
		exit(2);
	}
	tester.close();
}

bool	checkDecimalNumber(const std::string& realNum, const size_t& strSize)
{
	size_t	idx = 0;
	bool	isNum = false;
	bool	isDecimalPoint = false;

	while (realNum[idx] == '+' || realNum[idx] == '-')
		idx++;
	while (idx < strSize)
	{
		if (realNum[idx] < '0' || realNum[idx] > '9')
		{
			if (realNum[idx] == '.' && isNum && !isDecimalPoint)
			{
				isNum = false;
				isDecimalPoint = true;
			}
			else
				return (true);
		}
		else
			isNum = true;
		idx++;
	}
	return (false);
}

bool	checkInteger(const std::string& str)
{
	size_t	strSize = str.size();
	for (size_t idx = 0; idx < strSize; idx++)
	{
		if (str[idx] < '0' || str[idx] > '9')
			return (true);
	}
	return (false);
}

bool	checkFormat(const std::string& line, const std::string& finder, size_t cnt)
{
	size_t	start, beforeLoc, curLoc;
	size_t	curCnt = cnt;
	start = beforeLoc = curLoc = 0;
	while (curCnt--)
	{
		curLoc = line.find(finder, start);
		if (curCnt == cnt - 1 && curLoc == std::string::npos)
			return (true);
		if (beforeLoc == std::string::npos || (beforeLoc && curLoc - beforeLoc == 1))
			return (true);
		beforeLoc = curLoc;
		start = curLoc + 1;
	}
	if (curLoc == 0 || curLoc == line.size() - finder.size())
		return (true);
	curLoc = line.find(finder, start);
	if (curLoc != std::string::npos)
		return (true);
	return (false);
}

bool	checkDate(const std::string& date, const std::string& file, int lineNum)
{
	std::string year;
	std::string month;
	std::string day;

	if (checkFormat(date, "-", 2))
	{
		std::cerr << "Error: [DB File: " << file << "(line " << lineNum << ")] \"" << date << "\"" << '\n';
		std::cerr << "  - The \"date\" format is \"Year-Month-Day\"" << '\n';
		return (true);
	}
	std::istringstream dateManager(date);
	std::getline(dateManager, year, '-');
	std::getline(dateManager, month, '-');
	std::getline(dateManager, day, '-');
	if (checkInteger(year))
	{
		std::cerr << "Error: [DB File: " << file << "(line " << lineNum << ")] Year: \"" << year << "\"" << '\n';
		std::cerr << "  - The \"year\" of date must be consisted of number" << '\n';
		return (true);
	}
	int	realYear = static_cast<int>(atof(year.c_str()));
	if (year.size() != 4 || !(realYear >= 2009 && realYear <= 2050))
	{
		std::cerr << "Error: [DB File: " << file << "(line " << lineNum << ")] Year: \"" << year << "\"" << '\n';
		std::cerr << "  - The \"year\" input must be between 2009 to 2050" << '\n';
		return (true);
	}
	if (checkInteger(month))
	{
		std::cerr << "Error: [DB File: " << file << "(line " << lineNum << ")] Month: \"" << month << "\"" << '\n';
		std::cerr << "  - The \"month\" of date must be consisted of number" << '\n';
		return (true);
	}
	int realMonth = static_cast<int>(atof(month.c_str()));
	if (month.size() != 2 || !(realMonth >= 1 && realMonth <= 12))
	{
		std::cerr << "Error: [DB File: " << file << "(line " << lineNum << ")] Month: \"" << month << "\"" << '\n';
		std::cerr << "  - The \"month\" input must be between 01 to 12" << '\n';
		return (true);
	}
	if (checkInteger(day))
	{
		std::cerr << "Error: [DB File: " << file << "(line " << lineNum << ")] Day: \"" << day << "\"" << '\n';
		std::cerr << "  - The \"day\" of date must be consisted of number" << '\n';
		return (true);
	}
	int realDay = static_cast<int>(atof(day.c_str()));
	int	dayOfMonth;
	switch(realMonth)
	{
		case 2:
			dayOfMonth = ((!(realYear % 4) && realYear % 100) || !(realYear % 400)) ? 29 : 28;
			break ;
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			dayOfMonth = 31;
			break ;
		case 4:
		case 6:
		case 9:
		case 11:
			dayOfMonth = 30;
			break ;
	}
	if (day.size() != 2 || (realDay < 1 || realDay > dayOfMonth))
	{
		std::cerr << "Error: [DB File: " << file << "(line " << lineNum << ")] Day: \"" << day << "\"" << '\n';
		std::cerr << "  - The \"day\" input \"" << ((realMonth >= 1 && realMonth <= 9) ? "0" : "") << realMonth << "\" is between 01 to " << dayOfMonth << '\n';
		return (true);
	}
	return (false);
}

void	checkDateAndExchangeRate(std::map<std::string, double>& db, const std::string& file, const std::string& line, int lineNum)
{
	std::istringstream dateExchangeRate(line);
	std::string date;
	std::string exchangeRate;
	std::getline(dateExchangeRate, date, ',');
	std::getline(dateExchangeRate, exchangeRate, ',');
	if (checkDate(date, file, lineNum))
		exit(3);
	if (checkDecimalNumber(exchangeRate, exchangeRate.size()))
	{
		std::cerr << "Error: [DB File: " << file << "(line " << lineNum << ")] Exchange_rate: \"" << exchangeRate << "\"" << '\n';
		std::cerr << "  - The \"exchange_rate\" is not a positive integer or positive decimal number" << '\n';
		exit(3);
	}
	double realExchangeRate = atof(exchangeRate.c_str());
	if (realExchangeRate < 0)
	{
		std::cerr << "Error: [DB File: " << file << "(line " << lineNum << ")] Exchange_rate: \"" << realExchangeRate << "\"" << '\n';
		std::cerr << "  - The \"exchange_rate\" is not a positive integer or positive decimal number" << '\n';
		exit(3);
	}
	db.insert(std::pair<std::string, double>(date, realExchangeRate));
}

bool calculate(std::map<std::string, double>& db, const std::string& date, double value)
{
	std::map<std::string, double>::iterator iter = db.lower_bound(date);
	if (iter == db.end())
		return (true);
	std::cout << date << " => " << value << " = " << iter->second * value << '\n';
	return (false);
}

void	checkDateAndValue(std::map<std::string, double>& db, const std::string& file, const std::string& line, int lineNum)
{
	std::string delimiter = " | ";
	size_t	delimiterLoc = line.find(delimiter);
	std::string date = line.substr(0, delimiterLoc);
	std::string value = line.substr(delimiterLoc + delimiter.size(), line.size() - (delimiterLoc + delimiter.size()));
	if (checkDate(date, line, lineNum))
		return ;
	if (checkDecimalNumber(value, value.size()))
	{
		std::cerr << "Error: [DB File: " << file << "(line " << lineNum << ")] Value: \"" << value << "\"" << '\n';
		std::cerr << "  - The \"value\" is not a positive integer or positive decimal number" << '\n';
		return ;
	}
	double realValue = atof(value.c_str());
	if (realValue < 0 || realValue > 1000)
	{
		std::cerr << "Error: [DB File: " << file << "(line " << lineNum << ")] Value: \"" << value << "\"" << '\n';
		std::cerr << "  - The range of the \"value\" is 0-1000" << '\n';
		return ;
	}
	if (calculate(db, date, realValue))
		std::cerr << "Error: [DB File: " << file << "(line " << lineNum << ")] " << date << " is not existed in data.csv" << "\"" << '\n';
}

void	readSubjectDBFile(std::map<std::string, double>& db, const std::string& file)
{
	std::string line;
	std::ifstream reader(file.c_str());
	int lineNum = 1;
	getline(reader, line);
	if (line.compare("date,exchange_rate"))
	{
		std::cerr << "Error: [DB File: " << file << "(line " << lineNum << ")] The text of 1st line is always 'date,exchange_rate'" << '\n';
		exit(3);
	}
	while (getline(reader, line))
	{
		++lineNum;
		if (!line.size())
		{
			std::cerr << "Error: [DB File: " << file << "(line " << lineNum << ")] no empty line" << '\n';
			exit(3);
		}
		if (checkFormat(line, ",", 1))
		{
			std::cerr << "Error: [DB File: " << file << "(line " << lineNum << ")] You must keep the 'date,exchange_rate' format" << '\n';
			exit(3);
		}
		checkDateAndExchangeRate(db, file, line, lineNum);
	}
	if (!db.size())
	{
		std::cerr << "Error: [DB File: " << file << "(line " << lineNum << ")] no contents" << '\n';
		exit(3);
	}
}

void	readInputDBFile(std::map<std::string, double>& db, const std::string& file)
{
	std::string line;
	std::ifstream reader(file.c_str());
	int lineNum = 1;
	(void)db;
	getline(reader, line);
	if (line.compare("date | value"))
		std::cerr << "Error: [DB File: " << file << "(line " << lineNum << ")] The text of 1st line is always 'date | value'" << '\n';
	std::cout << "------------------------------------------------------------" << '\n';
	while (getline(reader, line))
	{
		++lineNum;
		if (checkFormat(line, " | ", 1))
			std::cerr << "Error: [DB File: " << file << "(line " << lineNum << ")] You must keep the 'date | value' format" << '\n';
		else
			checkDateAndValue(db, file, line, lineNum);
		std::cout << "------------------------------------------------------------" << '\n';
	}
}

void    BitcoinExchange::exchange(const std::string& databaseFile)
{
    std::map<std::string, double> subjectDB;
	std::string subjectDBFile = "data.csv";
	std::string inputDBFile = databaseFile;
	testOpenFile(subjectDBFile);
	testOpenFile(inputDBFile);
	readSubjectDBFile(subjectDB, subjectDBFile);
	readInputDBFile(subjectDB, inputDBFile);
}
