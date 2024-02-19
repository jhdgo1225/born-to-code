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
    x = point.x;
    y = point.y;
    return *this;
}
