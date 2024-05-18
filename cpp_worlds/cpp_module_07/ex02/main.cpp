#include <iostream>
#include "Array.hpp"
#include <ctime>
#define MAX_VAL 750

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[2] = 4242;
		std::cout << numbers[2] << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL - 1] = 14124;
		std::cout << numbers[MAX_VAL - 1] << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
	std::cout << numbers.size() << '\n';
	std::cout << "==========================================" << '\n';
    for (int i = 0; i < MAX_VAL; i++)
    {
		std::cout << numbers[i] << '\n';
    }
	std::cout << "==========================================" << '\n';
	Array<int> copy(numbers);
	for (int i=0; i<10; i++)
	{
		std::cout << "--------------- [" << i + 1 << " 번째] ---------------" << '\n';
		std::cout << numbers[i] << '\n';
		std::cout << copy[i] << '\n';
	}
	std::cout << "-------- [Compare size] --------" << '\n';
	std::cout << numbers.size() << '\n';
	std::cout << copy.size() << '\n';
	Array<int> copy2(10);
	for (int i=0; i<10; i++)
		copy2[i] = (i + 1) * 6;
	std::cout << "==========================================" << '\n';
	copy = copy2;
	for (size_t i=0; i<copy.size(); i++)
		std::cout << copy[i] << '\n';
    std::cout << "==========================================" << '\n';
    Array<std::string> emptyArr;
    std::cout << emptyArr.size() << '\n';
    try {
        std::cout << emptyArr[0] << '\n';
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    delete [] mirror;
    return 0;
}
