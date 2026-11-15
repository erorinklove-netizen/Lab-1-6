#include "Equilateral.h"
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

// --- Реалізація методів вкладеного класу Equilateral::Triangle ---

void Equilateral::Triangle::setA(double a)
{
    if (a > 0)
        this->a = a;
    else
        this->a = 1.0;
}

void Equilateral::Triangle::setB(double b)
{
    if (b > 0)
        this->b = b;
    else
        this->b = 1.0;
}

void Equilateral::Triangle::setC(double c)
{
    if (c > 0)
        this->c = c;
    else
        this->c = 1.0;
}

bool Equilateral::Triangle::Init(double a, double b, double c)
{
    if (a > 0 && b > 0 && c > 0 && (a + b > c) && (a + c > b) && (b + c > a))
    {
        setA(a);
        setB(b);
        setC(c);
        return true;
    }
    else
    {
        setA(3.0);
        setB(4.0);
        setC(5.0);
        return false;
    }
}

void Equilateral::Triangle::Display() const
{
    cout << "Triangle sides: a = " << a << ", b = " << b << ", c = " << c << endl;
}

void Equilateral::Triangle::Read()
{
    double a, b, c;
    do {
        cout << "Enter triangle sides (a, b, c): ";
        cin >> a >> b >> c;
        if (!Init(a, b, c))
        {
            cout << "Error! The sum of two sides must be greater than the third, and sides must be > 0. Try again.\n";
        }
    } while (!(a > 0 && b > 0 && c > 0 && (a + b > c) && (a + c > b) && (b + c > a)));
}

string Equilateral::Triangle::toString() const
{
    stringstream sout;
    sout << "Triangle(a=" << a << ", b=" << b << ", c=" << c << ")";
    return sout.str();
}

double Equilateral::Triangle::perimeter() const
{
    return a + b + c;
}

void Equilateral::Triangle::getAngles(double& angleA, double& angleB, double& angleC) const
{
    const double PI = 3.14159265358979323846;
    angleA = acos((b * b + c * c - a * a) / (2 * b * c)) * 180.0 / PI;
    angleB = acos((a * a + c * c - b * b) / (2 * a * c)) * 180.0 / PI;
    angleC = acos((a * a + b * b - c * c) / (2 * a * b)) * 180.0 / PI;
}


// --- Реалізація методів класу-контейнера Equilateral ---

void Equilateral::calculateArea()
{
    double a = triangle.getA();
    area = (sqrt(3.0) / 4.0) * a * a;
}

void Equilateral::setTriangle(Triangle triangle)
{
    double a = triangle.getA();
    double b = triangle.getB();
    double c = triangle.getC();

    if (a == b && b == c)
    {
        this->triangle = triangle;
    }
    else
    {
        this->triangle.Init(a, a, a);
    }
    calculateArea();
}

bool Equilateral::Init(double side)
{
    if (side > 0)
    {
        Triangle t;
        t.Init(side, side, side);
        this->triangle = t;
        calculateArea();
        return true;
    }
    return false;
}

void Equilateral::Display() const
{
    cout << "--- Equilateral Triangle ---" << endl;
    triangle.Display();
    cout << "Area = " << area << endl;
}

void Equilateral::Read()
{
    double side;
    do {
        cout << "Enter the side of the equilateral triangle: ";
        cin >> side;
        if (!Init(side))
        {
            cout << "Error! Side must be greater than 0." << endl;
        }
    } while (side <= 0);
}

string Equilateral::toString() const
{
    stringstream sout;
    sout << "Equilateral [Triangle: " << triangle.toString() << ", Area: " << area << "]";
    return sout.str();
}