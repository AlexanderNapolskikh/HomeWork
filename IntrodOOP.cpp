
#include <iostream>
using namespace std;

// Task

// Реализуйте класс Дробь.Необходимо хранить числитель
// и знаменатель в качестве переменных - членов.
// Реализуйте функции - члены для ввода данных в переменные - члены,
// для выполнения арифметических операций(сложение,
// вычитание, умножение, деление, и т.д.).

class Fraction {

private:
    // Числитель
    int numerator;
    // Знаменатель
    int denominator;

public:

    // Обязательный ввод при создании объекта
    Fraction(int numerator, int denominator) {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    // Метод последующего ввода данных
    void overwriteValues(int numerator, int denomirator) {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    Fraction operator +(const Fraction& other) {
        int num = numerator * other.denominator + denominator * other.numerator;
        int denum = denominator * other.denominator;

        return Fraction(num, denum);
    }

    Fraction operator -(const Fraction& other) {
        int num = numerator * other.denominator - denominator * other.numerator;
        int denum = denominator * other.denominator;

        return Fraction(num, denum);
    }

    Fraction operator *(const Fraction& other) {
        int num = numerator * other.numerator;
        int denum = denominator * other.denominator;

        return Fraction(num, denum);
    }

    Fraction operator /(const Fraction& other) {
        int num = numerator * other.denominator;
        int denum = denominator * other.numerator;

        return Fraction(num, denum);
    }

    void showFract() {
        cout << numerator << "/" << denominator << endl;
    }

};

void main()
{
    Fraction drob1(1, 4);
    Fraction drob2(1, 3);

    drob1.showFract();
    drob2.showFract();

    cout << " Opetation" << endl;

    Fraction drob3 = drob1 + drob2;
    drob3.showFract();
    Fraction drob4 = drob1 - drob2;
    drob4.showFract();
    Fraction drob5 = drob1 * drob2;
    drob5.showFract();
    Fraction drob6 = drob1 / drob2;
    drob6.showFract();
}
