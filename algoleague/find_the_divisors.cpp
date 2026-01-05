#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
    long long number;
    cin >> number;
    vector<long long> divisors;
    for (long long i = 1; i * i <= number; i++)
    {
        if (number % i == 0)
        {
            divisors.push_back(i);
            if (i != (number / i))
            {
                divisors.push_back(number / i);
            }
        }
    }
    long long size = divisors.size();
    sort(divisors.begin(), divisors.end());
    cout << size << endl;
    for (long long j = 0; j < size; j++)
    {
        cout << divisors[j] << " ";
    }

    return 0;
}
