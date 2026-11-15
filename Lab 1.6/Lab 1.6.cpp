// Lab 1.6.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include "Equilateral.h"

using namespace std;

int main()
{
    cout << "=== DEMONSTRATION OF NESTED CLASSES (LAB 1.6) ===\n\n";

    // 1. Створення стаціонарного об'єкта та демонстрація методів
    cout << "1. Testing a single object (static creation):\n";
    Equilateral eq1;
    eq1.Init(6.0); // Рівносторонній трикутник зі стороною 6
    eq1.Display();
    cout << "toString(): " << eq1.toString() << endl;

    // Догодимо звернення до методів вкладеного класу через об'єкт контейнера
    double a, b, c;
    eq1.getTriangle().getAngles(a, b, c);
    cout << "Triangle angles: " << a << "°, " << b << "°, " << c << "°" << endl;
    cout << "Triangle perimeter: " << eq1.getTriangle().perimeter() << endl << endl;

    // 2. Інтерактивне введення через Read()
    cout << "2. Entering object data from keyboard:\n";
    Equilateral eq2;
    eq2.Read();
    eq2.Display();
    cout << "toString(): " << eq2.toString() << endl << endl;

    // 3. Створення масиву об'єктів у динамічній пам'яті
    cout << "3. Working with a dynamic array of objects:\n";
    int n = 2;
    Equilateral* eqArray = new Equilateral[n];

    eqArray[0].Init(4.5);
    eqArray[1].Init(10.0);

    for (int i = 0; i < n; i++)
    {
        cout << "\nArray element #" << i + 1 << ":" << endl;
        eqArray[i].Display();
        cout << "String representation: " << eqArray[i].toString() << endl;
    }

    // Звільнення динамічної пам'яті
    delete[] eqArray;

    return 0;
}