#include "ScalarConverter.hpp"

void    cvtToChar(double rawData)
{

}

void    cvtToInt(double rawData)
{
    
}

void    cvtToFloat(double rawData)
{
    
}

void    cvtToDouble(double rawData)
{
    
}

void    ScalarConverter::convert(std::string rawData)
{
    double  dbData = atof(rawData);
    cvtToChar(rawData);
    cvtToInt(rawData);
    cvtToFloat(rawData);
    cvtToDouble(rawData);
}