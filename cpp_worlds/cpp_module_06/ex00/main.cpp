#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./staticcast [Real Number Or '(+/-)inf[f]', 'nan[f]']" << '\n';
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}