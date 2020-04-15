#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int getCount(int n, int s)
{
   int i = 0;
   while (n > 0)
   {
        n = n / s;
        i++;
   }
   return i;
}

int toDecimal(int n, int from)
{
   int sum = 0;
   int count = getCount(n, 10);
   for (int i = 0; i < count; i++)
   {
       sum += (n % 10) * pow(from, i);
       n = n / 10;
   }

   return sum;
}

vector<int> transform(int n, int to)
{
    vector<int> arr;
    while (n > 0)
    {
        arr.push_back(n % to);
        n = n / to;
    }

    return arr;
}

int main()
{
    int n, from, to;
    cout << "Enter number: ";
    cin >> n;

    cout << "Enter source number system: ";
    cin >> from;

    cout << "Enter destination number system: ";
    cin >> to;

    int decimal = toDecimal(n, from);
    vector<int> arr = transform(decimal, to);

    cout << "Result in " <<  to << " number system: ";
    for (std::vector<int>::reverse_iterator it = arr.rbegin(); it != arr.rend(); ++it)
    {
       cout << *it;
    }

    return 0;
}
