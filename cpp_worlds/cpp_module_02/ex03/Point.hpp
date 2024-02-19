#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point
{
public:
    Point();
    Point(const Fixed& x, const Fixed& y);
    ~Point();
    Point(const Point& point);
    Point& operator=(const Point& point);
private:
    const Fixed x;
    const Fixed y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
