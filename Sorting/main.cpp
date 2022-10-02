#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

class Complex {
protected:
    double real;
    double image;
public:
    Complex(double real = 0.0, double image = 0.0) : real(real), image(image) {};

    double getModulus() const {
        return sqrt(this->real * this->real + this->image * this->image);
    }

    string toString() const {
        stringstream ss;
        if (this->real == 0 && this->image == 0) {
            ss << "0";
            return ss.str();
        }
        if (this->real != 0)
            ss << this->real;
        if (this->image < 0) {
            if (this->real != 0)
                ss << " - " << this->image * -1 << " * i";
            else
                ss << this->image << " * i";
        }
        else if (this->image > 0) {
            if (this->real != 0)
                ss << " + " << this->image << " * i";
            else
                ss << this->image << " * i";
        }
        return ss.str();
    }

    Complex operator+(const Complex &obj) const {
        Complex res;
        res.real = this->real + obj.real;
        res.image = this->image + obj.image;
        return res;
    }

    bool operator>(const Complex &obj) const {
        return (this->getModulus() > obj.getModulus());
    }

    bool operator>=(const Complex &obj) const {
        return (this->getModulus() >= obj.getModulus());
    }

    bool operator<(const Complex &obj) const {
        return (this->getModulus() < obj.getModulus());
    }

    bool operator<=(const Complex &obj) const {
        return (this->getModulus() <= obj.getModulus());
    }

    bool operator==(const Complex &obj) const {
        return (this->getModulus() == obj.getModulus());
    }

    bool operator!=(const Complex &obj) const {
        return (this->getModulus() != obj.getModulus());
    }
};

class StraightSelectionSort {
public:
    static void sort(Complex *list, int length) {
        for (int i = 0; i < length - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < length; j++) {
                if (list[minIndex].getModulus() > list[j].getModulus())
                    minIndex = j;
            }
            if (minIndex != i) {
                Complex temp = list[i];
                list[i] = list[minIndex];
                list[minIndex] = temp;
            }
        }
    }

    static void sort(Complex *list, int length, int left, int right) {
        for (int i = left; i < right; i++) {
            int minIndex = i;
            for (int j = i + 1; j < right; j++) {
                if (list[minIndex].getModulus() > list[j].getModulus())
                    minIndex = j;
            }
            if (minIndex != i) {
                Complex temp = list[i];
                list[i] = list[minIndex];
                list[minIndex] = temp;
            }
        }
    }
};

int main() {
    Complex a(1, 5);
    Complex b(5, 1);
    cout << a.getModulus() << endl;
    cout << a.toString() << endl;
    cout << (a > b);
    return 0;
}
