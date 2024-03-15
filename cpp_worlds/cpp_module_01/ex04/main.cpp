#include <iostream>
#include <fstream>

std::string ft_replace(const std::string& str, const std::string& oldStr, const std::string& replaceStr)
{
	std::string newStr;
	size_t findStr;
	size_t start = 0;
	size_t oldStrSize = oldStr.size();
	while (1)
	{
		findStr = str.find(oldStr, start);
		if (findStr == std::string::npos)
		{
			size_t strSize = str.size();
			if (strSize - start > 0)
				newStr.append(str.substr(start, strSize - start));
			break ;
		}
		if (findStr - start > 0)
			newStr.append(str.substr(start, findStr - start));
		newStr.append(replaceStr);
		start = findStr + oldStrSize;
	}
	return (newStr);
}

int main(int argc, char **argv)
{
	if (argc != 4)
		return (1);
	std::string oldFile = argv[1];
	std::ifstream readFile(oldFile.c_str());
	if (!readFile.is_open())
	{
		std::cout << "Readfile Open Error\n";
		return (1);
	}
	std::string new_file = oldFile.append(".replace");
	std::ofstream writeFile(new_file.c_str());
	if (!writeFile.is_open())
	{
		std::cout << "Writefile Open Error\n";
		readFile.close();
		return (1);
	}
	std::string str;
	std::string oldStr = argv[2];
	std::string replaceStr = argv[3];
	while (getline(readFile, str))
	{
		writeFile << ft_replace(str, oldStr, replaceStr);
		if (!readFile.eof())
			writeFile << '\n';
	}
	writeFile.close();
	readFile.close();
	return (0);
}
