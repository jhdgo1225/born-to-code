#include "Point.hpp"

float det(Point const& p1, Point const& p2, Point const& point)
{
    return ((p1.getXValue() * p2.getYValue() + point.getXValue() * p1.getYValue() + p2.getXValue() * point.getYValue()) \
                - (p1.getXValue() * point.getYValue() + p2.getXValue() * p1.getYValue() + point.getXValue() * p2.getYValue()));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    if ((det(a, b, point) > 0 && det(b, c, point) > 0 && det(c, a, point) > 0) 
        || (det(a, b, point) < 0 && det(b, c, point) < 0 && det(c, a, point) < 0))
        return (true);
    return (false);
}
