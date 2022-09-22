#include <iostream>
using namespace std;

class Complex
{
private:
	double re;
	double im;

public:
    Complex(double re = 0, double im = 0) // 3 Constructors
    {
        this->re = re;
        this->im = im;
        //
        cout << "Constructor. Created: (" << re << ", " << im << ").\n";
    }

    Complex(const Complex& other) : re(other.re), im(other.im)
    {
        //this->re = other.re;
        //this->im = other.im;
        //
        std::cout << "Constructor. Copied: (" << other.re << ", " << other.im << ").\n";
    }

    ~Complex()
    {
        std::cout << "Destructor. Deleted: (" << re << ", " << im << ").\n";
    }

    double getRe() const
    {
        return re;
    }

    double getIm() const
    {
        return im;
    }

    Complex add(Complex other)
    {
        re += other.getRe();
        im += other.getIm();

        return *this;
    }

    Complex operator +(Complex other)
    {
        cout << "\tstart operator +(Complex other)" << endl;
        //Complex res = Complex(re + other.getRe(), im + other.getIm());
        //return &res;
        //
        return Complex(re + other.getRe(), im + other.getIm());
    }

    friend Complex operator +(double d, Complex other)
    {
        cout << "\tstart operator +(double d, Complex other)" << endl;
        return other + d;
    }

    void operator =(Complex other)
    {
        cout << "\tstart operator =(Complex other)" << endl;
        re = other.re;
        im = other.im;
        cout << "Asignment: (" << re << ", " << im << ").\n";
    }

    friend istream& operator>>(istream& in, Complex& date)
    {
        cout << "Input Complex:\nre = ";
        in >> date.re;
        cout << "im = ";
        in >> date.im;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Complex& date)
    {
        out << "complex = (" << date.getRe() << ", " << date.getIm() << ")" << endl;
        return out;
    }
};


int main01()
{
    Complex a(1, 1);
    Complex b(2);
    cout << "a = (" << a.getRe() << ", " << a.getIm() << ").\n";
    cout << "b = (" << b.getRe() << ", " << b.getIm() << ").\n";
    //
    //a = a.add(b); // a.add(b);
    //
    //a = *(a + b);
    //a = a + b;
    a = a + 1; // int to double; double to Complex; a.operator+(1);
    //a = 1 + a;
    //a = 1 + a + b;
    // 
    //
    //cout << "a = (" << a.getRe() << ", " << a.getIm() << ").\n";
    /*
    //cout << a;
    //
    cin >> b;
    cout << b;
    */
    //
	cout << "done" << endl;
	system("pause");
    return 0;
}
