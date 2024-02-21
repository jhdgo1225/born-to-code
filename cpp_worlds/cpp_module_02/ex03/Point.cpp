#include "Point.hpp"

Point::Point()
    :x(0),
     y(0)
{
}

Point::Point(const Fixed& x, const Fixed& y)
    :x(x),
     y(y)
{
}

Point::~Point()
{
}

Point::Point(const Point& point)
    :x(point.x),
     y(point.y)
{
}

Point& Point::operator=(const Point& point)
{
    Fixed* nx = (Fixed *)&x;
    Fixed* ny = (Fixed *)&y;

    *nx = point.x;
    *ny = point.y;
    return *this;
}

float Point::getXValue() const
{
    return (x.toFloat());
}

float Point::getYValue() const
{
    return (y.toFloat());
}
