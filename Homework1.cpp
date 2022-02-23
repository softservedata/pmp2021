#include <iostream>
using namespace std;

int main()
{

    int a = 5;
    int b = 7;
    //additional variable

    int buf = a;
    a = b;
    b = buf;
    cout << "a=" << a << ", b=" << b << endl;

    //addition and substruction

    a = a + b;
    b = a - b;
    a = a - b;
    cout << "a=" << a << ", b=" << b << endl;

    //multiplication and division

    a = a * b;
    b = a / b;
    a = a / b;
    cout << "a=" << a << ", b=" << b << endl;


    //conjuction and disjuction

    a = (a & b) + (a | b);
    b = a + ((~b) + 1);
    a = a + (~b) + 1;
    cout << "a=" << a << ", b=" << b << endl;

    //shift operator

    for (int i = 0; i < 8; i++)
    {
        if ((a & (1 << i)) ^ (b & (1 << i)))
        {
            a = a ^ (1 << i);

            b = b ^ (1 << i);

        }
    }
    cout << "a=" << a << ", b=" << b << endl;



    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << "a=" << a << ", b=" << b << endl;




    return 0;
}