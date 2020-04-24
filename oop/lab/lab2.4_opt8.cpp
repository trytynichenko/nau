#include <exception>
#include <cmath>
#include <iostream>

using namespace std;

class Equation {
    protected:
        float a, b, c, d;
    public:
        float getResult()
        {
            float divisor = log(4 * b - c) * a;
            float dividend = b + c / d - 1;

            if(d == 0 || divisor == 0 || dividend == 0) {
                throw "Division by zero condition!";
            }

            return divisor / dividend;
        };
        void getData()
        {
            cout << "Enter a: ";
            cin >> a;
            cout << "Enter b: ";
            cin >> b;
            cout << "Enter c: ";
            cin >> c;
            cout << "Enter d: ";
            cin >> d;
        }
};

int main()
{
    int i;

    Equation eq[3];

    cout << "Mathematical Equation: (lg(4 * b - c) * a) / (b + c / d - 1)\n";
    for(i = 0; i < 3; i++)
    {
        cout<<"\nEnter details of " << i + 1 << " equation\n";
        eq[i].getData();
    }


    for(i = 0; i < 3; i++)
    {
        cout << "\nResult of Mathematical Equation #" << i + 1 << ": ";
        try {
            cout << eq[i].getResult() << endl;
        } catch(const char* msg) {
            cerr << msg << endl;
        }
    }


    return 0;
}
