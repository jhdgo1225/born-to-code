#include "Point.hpp"

void    printPoint(std::string name, Point& point)
{
    std::cout << name << " =>";
    std::cout << " x: " << point.getXValue() << ",";
    std::cout << " y: " << point.getYValue();
    std::cout << '\n';
}

void    isInTriangle(bool checkBSP)
{
    if (checkBSP)
        std::cout << "\033[1;32m" << "Random Point is In The Triangle" << "\033[0m" << '\n';
    else
        std::cout << "\033[1;31m"  << "Random Point is Not In The Triangle" << "\033[0m" << '\n';
}

int main(void)
{
    {
        std::cout << "\033[1;36m" << "[Case #1]: " << "\033[0m" << "Three Points On Axis X = 0" << '\n';
        Fixed x1(0);
        Fixed y1(1);
        Point p1(x1, y1);
        printPoint("p1", p1);

        Fixed x2(0);
        Fixed y2(3);
        Point p2(x2, y2);
        printPoint("p2", p2);

        Fixed x3(0);
        Fixed y3(24);
        Point p3(x3, y3);
        printPoint("p3", p3);

        Fixed x(110);
        Fixed y(10);
        Point randomPoint(x, y);
        printPoint("randomPoint", randomPoint);

        isInTriangle(bsp(p1, p2, p3, randomPoint));
        std::cout << '\n';
    }
    {
        std::cout << "\033[1;36m" << "[Case #2]: " << "\033[0m" << "Three Points On Axis Y = 3" << '\n';
        Fixed x1(-10);
        Fixed y1(3);
        Point p1(x1, y1);
        printPoint("p1", p1);

        Fixed x2(5);
        Fixed y2(3);
        Point p2(x2, y2);
        printPoint("p2", p2);

        Fixed x3(17);
        Fixed y3(3);
        Point p3(x3, y3);
        printPoint("p3", p3);

        Fixed x(-10);
        Fixed y(-1);
        Point randomPoint(x, y);
        printPoint("randomPoint", randomPoint);

        isInTriangle(bsp(p1, p2, p3, randomPoint));
        std::cout << '\n';
    }
    {
        std::cout << "\033[1;36m" << "[Case #3]: " << "\033[0m" << "First Triangle" << '\n';
        Fixed x1(-2);
        Fixed y1(6);
        Point p1(x1, y1);
        printPoint("p1", p1);

        Fixed x2(3);
        Fixed y2(8);
        Point p2(x2, y2);
        printPoint("p2", p2);

        Fixed x3(1);
        Fixed y3(2);
        Point p3(x3, y3);
        printPoint("p3", p3);

        Fixed x(0);
        Fixed y(4);
        Point randomPoint(x, y);
        printPoint("randomPoint", randomPoint);

        isInTriangle(bsp(p1, p2, p3, randomPoint));
        std::cout << '\n';
    }
    {
        std::cout << "\033[1;36m" << "[Case #4]: " << "\033[0m" << "Second Triangle" << '\n';
        Fixed x1(-3);
        Fixed y1(-1.5f);
        Point p1(x1, y1);
        printPoint("p1", p1);

        Fixed x2(-0.5f);
        Fixed y2(-1.5f);
        Point p2(x2, y2);
        printPoint("p2", p2);

        Fixed x3(2);
        Fixed y3(-0.5f);
        Point p3(x3, y3);
        printPoint("p3", p3);

        Fixed x(0);
        Fixed y(-1.25f);
        Point randomPoint(x, y);
        printPoint("randomPoint", randomPoint);

        isInTriangle(bsp(p1, p2, p3, randomPoint));
        std::cout << '\n';
    }
    {
        std::cout << "\033[1;36m" << "[Case #5]: " << "\033[0m" << "Third Triangle" << '\n';
        Fixed x1(-0.25f);
        Fixed y1(4);
        Point p1(x1, y1);
        printPoint("p1", p1);

        Fixed x2(0.5f);
        Fixed y2(2.25f);
        Point p2(x2, y2);
        printPoint("p2", p2);

        Fixed x3(0.6f);
        Fixed y3(0.65f);
        Point p3(x3, y3);
        printPoint("p3", p3);

        Fixed x(0.49f);
        Fixed y(1.096f);
        Point randomPoint(x, y);
        printPoint("randomPoint", randomPoint);

        isInTriangle(bsp(p1, p2, p3, randomPoint));
        std::cout << '\n';
    }
    {
        std::cout << "\033[1;36m" << "[Case #6]: " << "\033[0m" << "One Dot!" << '\n';
        Fixed x1(0);
        Fixed y1(0);
        Point p1(x1, y1);
        printPoint("p1", p1);

        Fixed x2(0);
        Fixed y2(0);
        Point p2(x2, y2);
        printPoint("p2", p2);

        Fixed x3(0);
        Fixed y3(0);
        Point p3(x3, y3);
        printPoint("p3", p3);

        Fixed x(0);
        Fixed y(0);
        Point randomPoint(x, y);
        printPoint("randomPoint", randomPoint);

        isInTriangle(bsp(p1, p2, p3, randomPoint));
        std::cout << '\n';
    }
    return (0);
}
