#include "pch.h"
#include "CppUnitTest.h"
#include "D:\education\ООП\Lab 1.6\Equilateral.h" // Шлях до вашого заголовочного файлу Equilateral.h

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        // --- Тести для вкладеного класу Equilateral::Triangle ---

        TEST_METHOD(TestTriangleValidInit)
        {
            Equilateral::Triangle t;
            bool result = t.Init(3.0, 4.0, 5.0);

            Assert::IsTrue(result);
            Assert::AreEqual(3.0, t.getA());
            Assert::AreEqual(4.0, t.getB());
            Assert::AreEqual(5.0, t.getC());
        }

        TEST_METHOD(TestTriangleInvalidInit)
        {
            Equilateral::Triangle t;
            // Сума двох сторін менша за третю (невалідний трикутник)
            bool result = t.Init(1.0, 2.0, 10.0);

            Assert::IsFalse(result);
            // Перевіряємо спрацювання значення за замовчуванням
            Assert::AreEqual(3.0, t.getA());
        }

        TEST_METHOD(TestTrianglePerimeter)
        {
            Equilateral::Triangle t;
            t.Init(3.0, 4.0, 5.0);

            Assert::AreEqual(12.0, t.perimeter());
        }

        TEST_METHOD(TestTriangleAngles)
        {
            Equilateral::Triangle t;
            t.Init(3.0, 4.0, 5.0); // Прямокутний трикутник 3-4-5
            double angleA, angleB, angleC;
            t.getAngles(angleA, angleB, angleC);

            // Перевіряємо кут C (має бути 90 градусів з похибкою 0.1)
            Assert::AreEqual(90.0, angleC, 0.1);
        }

        // --- Тести для класу-контейнера Equilateral ---

        TEST_METHOD(TestEquilateralValidInit)
        {
            Equilateral eq;
            bool result = eq.Init(6.0);

            Assert::IsTrue(result);
            Assert::AreEqual(6.0, eq.getTriangle().getA());
            Assert::AreEqual(6.0, eq.getTriangle().getB());
            Assert::AreEqual(6.0, eq.getTriangle().getC());
        }

        TEST_METHOD(TestEquilateralArea)
        {
            Equilateral eq;
            eq.Init(6.0);
            // Площа для сторони 6 = (sqrt(3)/4) * 36 ≈ 15.58845
            Assert::AreEqual(15.5885, eq.getArea(), 0.001); // 0.001 — допустима похибка (tolerance)
        }

        TEST_METHOD(TestEquilateralInvalidInit)
        {
            Equilateral eq;
            bool result = eq.Init(-4.0); // Від'ємна сторона

            Assert::IsFalse(result);
        }
    };
}