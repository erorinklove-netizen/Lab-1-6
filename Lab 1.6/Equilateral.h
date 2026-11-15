#pragma once
#include <string>

using namespace std;

class Equilateral
{
public:
    // Вкладений клас Triangle
    class Triangle
    {
    private:
        double a, b, c;

    public:
        double getA() const { return a; }
        double getB() const { return b; }
        double getC() const { return c; }

        void setA(double a);
        void setB(double b);
        void setC(double c);

        bool Init(double a, double b, double c);
        void Display() const;
        void Read();
        string toString() const;

        double perimeter() const;
        void getAngles(double& angleA, double& angleB, double& angleC) const;
    };

private:
    Triangle triangle;
    double area;

    void calculateArea();

public:
    Triangle getTriangle() const { return triangle; }
    double getArea() const { return area; }

    void setTriangle(Triangle triangle);

    bool Init(double side);
    void Display() const;
    void Read();
    string toString() const;
}; 
